# $FreeBSD$

PORTNAME=	ndproxy
PORTVERSION=	3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	fbsd.bugzilla@fenyo.net
COMMENT=	Implementation of IPv6 Neighbor Discovery proxy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod

SUB_FILES=	pkg-message

USE_RC_SUBR=	ndproxy
USE_GITHUB=	yes
GH_ACCOUNT=	AlexandreFenyo

# build for a kernel with 'options VIMAGE'
CFLAGS+=	-DVIMAGE

PLIST_FILES=	${KMODDIR}/${PORTNAME}.ko man/man4/${PORTNAME}.4.gz

pre-build:
	(cd ${BUILD_WRKSRC}; ${MAKE} depend)

do-install:
	${INSTALL_KLD} ${WRKSRC}/${PORTNAME}.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.4 ${STAGEDIR}${PREFIX}/man/man4/

.include <bsd.port.mk>
