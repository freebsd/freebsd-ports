PORTNAME=	ndproxy
PORTVERSION=	3.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	fbsd.bugzilla@fenyo.net
COMMENT=	Implementation of IPv6 Neighbor Discovery proxy
WWW=		http://www.fenyo.net/newweb/ndproxy.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler kmod

BROKEN_FreeBSD_15=	ndpacket.c:186:46: error: incomplete definition of type 'struct ifnet'
BROKEN_FreeBSD_16=	ndpacket.c:186:46: error: incomplete definition of type 'struct ifnet'

SUB_FILES=	pkg-message

USE_RC_SUBR=	ndproxy
USE_GITHUB=	yes
GH_ACCOUNT=	AlexandreFenyo

# build for a kernel with 'options VIMAGE'
CFLAGS+=	-DVIMAGE ${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-error=strict-prototypes

PLIST_FILES=	${KMODDIR}/${PORTNAME}.ko share/man/man4/${PORTNAME}.4.gz

pre-build:
	(cd ${BUILD_WRKSRC}; ${MAKE} depend)

do-install:
	${INSTALL_KLD} ${WRKSRC}/${PORTNAME}.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.4 ${STAGEDIR}${PREFIX}/share/man/man4/

.include <bsd.port.mk>
