# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	xpns
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	misc cad
MASTER_SITES=	http://robotics.ee.uwa.edu.au/pns/ftp/
DISTNAME=	pns_source.tar
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Petri-Net Simulator for Xwindows

NO_WRKSUBDIR=	yes

USE_XORG=	x11 xaw
MAKEFILE=	makefile
ALL_TARGET=	pns

PORTDOCS=	*
PLIST_FILES=	bin/xpns \
		libexec/xpns/pns \
		%%DATADIR%%/pns.hlp \
		%%DATADIR%%/pns.shell
PLIST_DIRS=	%%DATADIR%% \
		libexec/xpns

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xpns

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} xpns ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/xpns
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pns ${STAGEDIR}${PREFIX}/libexec/xpns)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} pns.hlp pns.shell ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.net ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
