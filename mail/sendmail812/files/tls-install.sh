#!/bin/sh
#
CADIR="${CADIR-${DESTDIR}/etc/mail/certs}"
FILSEDIR="${FILESDIR-/usr/ports/mail/sendmail/files}"
REALM=`hostname`

echo "creating: ${CADIR} on ${REALM}"
for i in certs crl newcerts private
do
	if test ! -d "${CADIR}/${i}"
	then
		mkdir -p "${CADIR}/${i}"
	fi
done
chmod 0600 "${CADIR}/private"
cd "${CADIR}" || exit 65

if test ! -f openssl.cnf
then
	echo "generating: openssl.cnf"
	sed -e "s=./demoCA=${CADIR}=" /etc/ssl/openssl.cnf > "openssl.cnf"
fi

if test ! -f "serial"
then
	echo "generating: serial"
	echo "01" > "serial"
fi

if test ! -f "index.txt"
then
	echo "generating: index.txt"
	cp /dev/null "index.txt"
fi

if test ! -f "cacert.pem"
then
	echo "generating CA"
	openssl req -new -x509 -config openssl.cnf \
		-keyout private/cakey.pem \
		-out cacert.pem
	chmod 0600 "private/cakey.pem"
fi

if test ! -f "sendmailcert.pem"
then
	if test ! -f "private/sendmailkey.pem"
	then
		echo "generating server CERT"
		umask 0066
		openssl req -nodes -new -x509 -config openssl.cnf \
			-keyout private/sendmailkey.pem \
			-out private/sendmailkey.pem
	fi
	if test ! -f "newcsr.pem"
	then
		echo "signing CERT1"
		openssl x509 -x509toreq \
			-in private/sendmailkey.pem \
			-signkey private/sendmailkey.pem \
			-out newcsr.pem
	fi
	if test ! -f "sendmailcert.pem"
	then
		echo "signing CERT2"
		openssl ca -config openssl.cnf -policy policy_anything \
			-out sendmailcert.pem \
			-infiles newcsr.pem
		rm -f newcsr.pem
	fi
fi

sed 's/^X//' << 'END-of-files/tls.m4'
X# links:
X# http://www.sendmail.org/~ca/email/starttls.html
X# http://www.ofb.net/~jheiss/sendmail/tlsandrelay.shtml
X#
X# You may need to add this to your sendmail.mc file:
X
Xdefine(`CERT_DIR', `MAIL_SETTINGS_DIR`'certs')dnl
Xdefine(`confCACERT_PATH', `CERT_DIR')dnl
Xdefine(`confCACERT', `CERT_DIR/cacert.pem')dnl
Xdefine(`confSERVER_CERT', `CERT_DIR/sendmailcert.pem')dnl
Xdefine(`confSERVER_KEY', `CERT_DIR/private/sendmailkey.pem')dnl
X
END-of-files/tls.m4
exit
