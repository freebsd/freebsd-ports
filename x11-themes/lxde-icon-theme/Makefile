# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lxde-icon-theme
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	SF/lxde/LXDE%20Icon%20Theme/lxde-icon-theme-${PORTVERSION}/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	LXDE Icon Theme

LICENSE=	GPLv3

USES=		gmake iconv tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	YES

PORTDOCS=	AUTHORS
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|cp -raf --no-preserve=ownership|cp -RpPf|' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
