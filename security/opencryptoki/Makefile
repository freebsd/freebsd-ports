# Created by: Ralf Meister
# $FreeBSD$

PORTNAME=	opencryptoki
PORTVERSION=	3.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Open PKCS\#11 implementation library

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtspi.so:security/trousers

USES=		alias autoreconf gmake libtool localbase ssl tar:tgz
USE_GCC=	any
USE_OPENLDAP=	yes
USE_LDCONFIG=	${PREFIX}/lib/opencryptoki
USE_GITHUB=	yes
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-swtok --enable-tpmtok \
		--enable-icsftok \
		--disable-crtok --disable-aeptok \
		--disable-ccatok --disable-bcomtok \
		--disable-pkcscca_migrate \
		--with-lockdir=/var/run/opencryptoki \
		--with-logdir=/var/log/opencryptoki \
		--localstatedir=/var \
		--with-openssl=${OPENSSLBASE} \
		--with-pkcs11user=${USERS} \
		--with-pkcs11group=${GROUPS} \
		ac_cv_path_CHGRP=true
USE_RC_SUBR=	pkcsslotd
SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"
USERS=		_pkcs11
GROUPS=		_pkcs11

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/opencryptoki.conf \
	    ${STAGEDIR}${ETCDIR}/opencryptoki.conf.sample
	${RMDIR} ${STAGEDIR}/var/run/opencryptoki/* \
	    ${STAGEDIR}/var/run/opencryptoki

.include <bsd.port.mk>
