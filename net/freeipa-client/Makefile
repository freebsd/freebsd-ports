PORTNAME=	freeipa-client
DISTVERSION=	4.13.0
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
