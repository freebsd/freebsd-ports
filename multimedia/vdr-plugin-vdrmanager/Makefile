# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-vdrmanager
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/828/
DISTNAME=	${PORTNAME:S/-plugin//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - VDR-Manager server plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PATCH_STRIP=	-p1

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins
	${INSTALL_DATA} ${WRKSRC}/examples/plugin.vdrmanager.conf \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/plugin.vdrmanager.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
