#!/bin/sh
#
CADIR="${CADIR-${DESTDIR}/etc/mail/certs/CA}"
FILSEDIR="${FILESDIR-/usr/ports/mail/sendmail/files}"
REALM=`hostname`

echo "creating: ${CADIR} on ${REALM}"
for i in certs crl newcerts private ../private
do
	if test ! -d "${CADIR}/${i}"
	then
		mkdir -p "${CADIR}/${i}"
	fi
done
chmod 0700 "${CADIR}/private" "${CADIR}/../private"
cd "${CADIR}" || exit 65

if test ! -f openssl.cnf
then
	echo "generating: openssl.cnf"
	sed -e "s=./demoCA=${CADIR}=" /etc/ssl/openssl.cnf > "openssl.cnf"
fi

if test ! -f "serial"
then
	echo "generating: serial"
	umask 0022
	echo "01" > "serial"
fi

if test ! -f "index.txt"
then
	echo "generating: index.txt"
	umask 0022
	cp /dev/null "index.txt"
fi

if test ! -f "cacert.pem"
then
	echo "generating CA"
	umask 0077
	openssl req -new -x509 -config openssl.cnf \
		-keyout private/cakey.pem \
		-out cacert.pem
fi

if test ! -f "../sendmailcert.pem"
then
	if test ! -f "../private/sendmailkey.pem"
	then
		echo "creating cert signing request"
		umask 0066
		openssl req -nodes -new -x509 -config openssl.cnf \
			-keyout ../private/sendmailkey.pem \
			-out ../private/sendmailkey.pem
	fi
	if test ! -f "newcsr.pem"
	then
		echo "self signing cert"
		umask 0066
		openssl x509 -x509toreq \
			-in ../private/sendmailkey.pem \
			-signkey ../private/sendmailkey.pem \
			-out newcsr.pem
	fi
	if test ! -f "sendmailcert.pem"
	then
		echo "signing cert"
		openssl ca -config openssl.cnf -policy policy_anything \
			-out ../sendmailcert.pem \
			-infiles newcsr.pem
		rm -f newcsr.pem
	fi
fi

sed 's/^X//' << 'END-of-files/tls.m4'
X# links:
X# http://www.sendmail.org/~gshapiro/
X# http://www.sendmail.org/~ca/email/starttls.html
X# http://www.ofb.net/~jheiss/sendmail/tlsandrelay.shtml
X#
X# You may need to add this to your sendmail.mc file:
X
Xdefine(`confCACERT_PATH', `MAIL_SETTINGS_DIR`'certs')dnl
Xdefine(`confCACERT', `confCACERT_PATH/CA/cacert.pem')dnl
Xdefine(`confSERVER_CERT', `confCACERT_PATH/sendmailcert.pem')dnl
Xdefine(`confSERVER_KEY', `confCACERT_PATH/private/sendmailkey.pem')dnl
Xdefine(`confCLIENT_CERT', `confCACERT_PATH/sendmailcert.pem')dnl
Xdefine(`confCLIENT_KEY', `confCACERT_PATH/private/sendmailkey.pem')dnl
X
END-of-files/tls.m4
exit
