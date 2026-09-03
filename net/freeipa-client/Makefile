PORTNAME=	freeipa-client
DISTVERSION=	4.13.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://releases.pagure.org/freeipa/
DISTNAME=	freeipa-${DISTVERSION}

MAINTAINER=	kiwi@FreeBSD.org
COMMENT=	FreeIPA Client tools
WWW=		https://www.freeipa.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}

LIB_DEPENDS=	libcmocka.so:sysutils/cmocka \
		libcurl.so:ftp/curl \
		libini_config.so:devel/ding-libs \
		libjansson.so:devel/jansson \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpopt.so:devel/popt \
		libpwquality.so:security/libpwquality \
		libsasl2.so:security/cyrus-sasl2 \
		libxmlrpc.so:net/xmlrpc-c

RUN_DEPENDS=	${LOCALBASE}/bin/chronyc:net/chrony \
		${LOCALBASE}/sbin/certmonger:security/certmonger \
		${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gssapi>0:security/py-gssapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>0:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>0:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-augeas>0:textproc/py-python-augeas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>0:net/py-python-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		sssd2>0:security/sssd2 \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}

USES=		autoreconf gettext gmake gssapi:mit ldap libtool \
		localbase:ldflags ssl pkgconfig python

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-server \
		--with-ipaplatform=freebsd \
		--without-ipatests \
		--without-server

# Don't bytecode python files
MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1

# Remove all systemd dependant things
EXTRACT_AFTER_ARGS=	--exclude client/systemd --exclude daemons/dnssec \
			--exclude daemons/ipa-otpd --exclude \
			daemons/ipa-slapi-plugins --exclude init/systemd \
			--exclude init/tmpfilesd

PLIST_SUB=	DISTVERSION=${DISTVERSION}

# Make sample configuration file
post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/ipa/epn.conf ${STAGEDIR}${PREFIX}/etc/ipa/epn.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/ipa-client/pki
	@${MKDIR} ${STAGEDIR}/var/db/ipa-client/sysrestore
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/krb5.conf.d

post-stage:
	${REINPLACE_CMD} -e 's|${STAGEDIR}||'   \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipaclient/install_files.txt
	${REINPLACE_CMD} -e 's|${STAGEDIR}||'   \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipapython/install_files.txt
	${REINPLACE_CMD} -e 's|${STAGEDIR}||'   \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipaplatform/install_files.txt
	${REINPLACE_CMD} -e 's|${STAGEDIR}||'   \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipalib/install_files.txt
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipaclient/install_files.txt.bak
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipapython/install_files.txt.bak
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipaplatform/install_files.txt.bak
	${RM} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ipalib/install_files.txt.bak

.include <bsd.port.mk>
