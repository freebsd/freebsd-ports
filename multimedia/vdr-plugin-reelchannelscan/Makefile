# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-reelchannelscan
PORTVERSION=	0.6.1b1.7.15
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox \
		http://ppa.launchpad.net/yavdr/stable-vdr/ubuntu/pool/main/v/vdr-plugin-reelchannelscan/
DISTFILES=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION:S/b/+beta/}${DISTVERSIONSUFFIX}.orig${EXTRACT_SUFX} \
		${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION:S/b/+beta/}${DISTVERSIONSUFFIX}-27yavdr1.debian${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - Reelchannelscan plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/b1.7.15//}

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS NLS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/transponders
	${INSTALL_DATA} ${WRKDIR}/debian/transponders/*.tpl \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/transponders

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
