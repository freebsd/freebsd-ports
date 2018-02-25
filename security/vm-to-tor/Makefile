# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	vm-to-tor
PORTVERSION=	0.150519
CATEGORIES=	security net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Connect virtual machines to the tor network

LICENSE=	BSD4CLAUSE

RUN_DEPENDS=	tor:security/tor \
		tiny-dhcp-server:net/tiny-network-utilities

USE_GITHUB=	yes
GH_ACCOUNT=	yurivict
GH_TAGNAME=	17bdb91

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

PLIST_FILES+=	etc/rc.d/${PORTNAME} bin/vm-ctrl
PLIST_FILES+=	"@sample etc/${PORTNAME}.rc.conf.simple.sample"
PLIST_FILES+=	"@sample etc/${PORTNAME}.rc.conf.complex.sample"

post-patch:
	@${REINPLACE_CMD} 's|"/usr/local"|"${LOCALBASE}"|' \
		${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|etc/rc\.conf\.|etc/${PORTNAME}.rc.conf.|' \
		${WRKSRC}/rc.conf.*.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/vm-ctrl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.conf.simple.sample \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.rc.conf.simple.sample
	${INSTALL_SCRIPT} ${WRKSRC}/rc.conf.complex.sample \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.rc.conf.complex.sample

.include <bsd.port.mk>
