# New ports collection makefile for:	vdr-plugin-reelchannelscan
# Date created:		Fri Apr 29 17:44:18 CEST 2011
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-reelchannelscan
PORTVERSION=	0.6.1b1.7.15
PORTREVISION=	10
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox \
		http://ppa.launchpad.net/yavdr/stable-vdr/ubuntu/pool/main/v/vdr-plugin-reelchannelscan/
DISTFILES=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION:S/b/+beta/}${DISTVERSIONSUFFIX}.orig${EXTRACT_SUFX} \
		${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION:S/b/+beta/}${DISTVERSIONSUFFIX}-27yavdr1.debian${EXTRACT_SUFX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - Reelchannelscan plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/b1.7.15//}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
	${MKDIR} ${PREFIX}/etc/vdr/plugins/transponders
	${INSTALL_DATA} ${WRKDIR}/debian/transponders/*.tpl \
		${PREFIX}/etc/vdr/plugins/transponders
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
