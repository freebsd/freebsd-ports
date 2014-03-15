# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-infosatepg
PORTVERSION=	0.0.11
PORTREVISION=	17
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/342/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - infosat EPG plugin

USES=		tar:tgz
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}/var/cache/vdr/${PLUGIN}

.include <bsd.port.mk>
