PORTNAME=	vdr-plugin-ttxtsubs
PORTVERSION=	0.2.4
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/725/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - teletext subtitle plugin
WWW=		https://projects.vdr-developer.org/projects/plg-ttxtsubs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on abandoned fork of VDR
EXPIRATION_DATE=2023-06-30

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS NLS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
