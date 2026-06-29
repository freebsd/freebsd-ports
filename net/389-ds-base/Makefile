PORTNAME=	389-ds-base
DISTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/389ds/389-ds-base/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Enterprise-class LDAP directory server
WWW=		https://www.port389.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USERS=		dirsrv
GROUPS=		dirsrv

BUILD_DEPENDS=	${LOCALBASE}/include/crypt.h:security/libxcrypt \
		cargo:lang/rust \
		rsync:net/rsync

LIB_DEPENDS=	libcrack.so:security/cracklib \
		libicui18n.so:devel/icu \
		libjson-c.so:devel/json-c \
		liblmdb.so:databases/lmdb \
		libnetsnmp.so:net-mgmt/net-snmp \
		libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libpcre2-8.so:devel/pcre2 \
		libpkg.so:ports-mgmt/pkg \
		libsasl2.so:security/cyrus-sasl2

USES=		autoreconf gmake ldap libtool localbase:ldflags perl5 pkgconfig \
		python:3.12+ shebangfix ssl tar:bzip2

USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/dirsrv
USE_PERL5=	run

SHEBANG_FILES=	ldap/admin/src/logconv.pl ldap/admin/src/logconv.py \
		ldap/admin/src/scripts/ds-logpipe.py \
		ldap/admin/src/scripts/ds-replcheck \
		ldap/servers/slapd/mkDBErrStrs.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-rust-offline \
		--with-netsnmp=${LOCALBASE} \
		--with-openldap=${LOCALBASE} \
		--with-localrundir=/var/run \
		--with-pythonexec=${PYTHON_CMD}

MAKE_ENV=	CARGO_HOME=${WRKSRC}/.cargo \
		CARGO_NET_OFFLINE=true \
		PYTHON=${PYTHON_CMD}

LIBS+=		-lexecinfo

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	${MKDIR} ${STAGEDIR}/var/db/dirsrv \
		${STAGEDIR}/var/log/dirsrv

.include <bsd.port.mk>
