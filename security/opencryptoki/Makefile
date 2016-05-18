# Created by: Ralf Meister
# $FreeBSD$

PORTNAME=	opencryptoki
PORTVERSION=	3.5
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Open PKCS\#11 implementation library

LICENSE=	CPL
LICENSE_NAME=	Common Public License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libtspi.so:security/trousers

USES=		alias autoreconf gmake libtool tar:tgz
USE_LDCONFIG=	${PREFIX}/lib/opencryptoki
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-swtok --enable-tpmtok \
		--disable-crtok --disable-aeptok \
		--disable-ccatok --disable-bcomtok \
		--disable-pkcscca_migrate \
		--with-lockdir=/var/run/opencryptoki \
		--with-logdir=/var/log/opencryptoki \
		--localstatedir=/var \
		--with-pkcs11user=${USERS} \
		--with-pkcs11group=${GROUPS} \
		ac_cv_path_CHGRP=true
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_RC_SUBR=	pkcsslotd
SUB_FILES=	pkg-message
SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}"
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"
USERS=		_pkcs11
GROUPS=		_pkcs11

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/opencryptoki.conf \
	    ${STAGEDIR}${ETCDIR}/opencryptoki.conf.sample
	${RMDIR} ${STAGEDIR}/var/run/opencryptoki/swtok \
	    ${STAGEDIR}/var/run/opencryptoki/tpm \
	    ${STAGEDIR}/var/run/opencryptoki

.include <bsd.port.mk>
