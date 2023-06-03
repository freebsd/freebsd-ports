PORTNAME=	vdr-plugin-sleeptimer
PORTVERSION=	0.8.2
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/652/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - sleep timer plugin
WWW=		https://projects.vdr-developer.org/projects/plg-sleeptimer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on abandoned fork of VDR
EXPIRATION_DATE=2023-06-30

USES=		tar:tgz
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}

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
