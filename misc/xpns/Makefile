# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	xpns
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	misc cad
MASTER_SITES=	http://robotics.ee.uwa.edu.au/pns/ftp/
DISTNAME=	pns_source.tar
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Petri-Net Simulator for Xwindows

LICENSE=	NONE

NO_WRKSUBDIR=	yes

USE_XORG=	x11 xaw xmu xt xext
MAKEFILE=	makefile
ALL_TARGET=	pns

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/xpns \
		libexec/xpns/pns \
		%%DATADIR%%/pns.hlp \
		%%DATADIR%%/pns.shell

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/xpns

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/xpns
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${STAGEDIR}${PREFIX}/libexec/xpns
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${WRKSRC}/pns.shell ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.net ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
