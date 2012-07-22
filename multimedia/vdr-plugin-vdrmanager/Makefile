# New ports collection makefile for:	vdr-plugin-vdrmanager
# Date created:		Fri Mar 23 2012
# Whom:			Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-vdrmanager
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/828/
DISTNAME=	${PORTNAME:S/-plugin//}-${PORTVERSION}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - VDR-Manager server plugin

PATCH_STRIP=	-p1
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install:
	@${MKDIR} ${PREFIX}/etc/vdr/plugins
	@${INSTALL_DATA} ${WRKSRC}/examples/plugin.vdrmanager.conf ${PREFIX}/etc/vdr/plugins/plugin.vdrmanager.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
