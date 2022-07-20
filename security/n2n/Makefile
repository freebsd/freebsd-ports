PORTNAME=	n2n
PORTVERSION=	${PORT_V_MAJOR}.${PORT_V_MINOR}
CATEGORIES=	security net net-vpn

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Layer Two Peer-to-peer VPN

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake ssl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORT_V_MAJOR=	2
PORT_V_MINOR=	8
PORT_V_PATCH=	0

USE_GITHUB=	yes
GH_ACCOUNT=	ntop

PLIST_FILES=	sbin/edge \
		sbin/supernode \
		man/man1/supernode.1.gz \
		man/man7/n2n.7.gz \
		man/man8/edge.8.gz

LIB_DEPENDS+=	libzstd.so:archivers/zstd

post-patch:
	@${SED} -e "s/@N2N_MAJOR@/${PORT_V_MAJOR}/g" \
		-e "s/@N2N_MINOR@/${PORT_V_MINOR}/g" \
		-e "s/@N2N_PATCH@/${PORT_V_PATCH}/g" \
		-e "s/@N2N_VERSION_SHORT@/${PORT_V_MAJOR}.${PORT_V_MINOR}.${PORT_V_PATCH}/g" \
		${WRKSRC}/configure.seed >${WRKSRC}/configure.ac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/edge ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/supernode ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/edge.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/supernode.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/n2n.7 ${STAGEDIR}${MANPREFIX}/man/man7

.include <bsd.port.mk>
