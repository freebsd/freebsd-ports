# New ports collection makefile for:	vdr-plugin-eepg
# Date created:		Wed Dec 21 18:34:25 CET 2011
# Whom:			Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-eepg
PORTVERSION=	0.0.6p2011071921
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/p.*/pre/}-0-g${GITHASH}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - extended EPG plugin

GITHASH=	e7383ed
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${GITHASH}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install:
	@${INSTALL} -o ${VDR_USER} -g ${VDR_GROUP} -d ${PREFIX}/etc/vdr/plugins/${PLUGIN}
	@${INSTALL_DATA} ${WRKSRC}/eepg.equiv.IT ${PREFIX}/etc/vdr/plugins/${PLUGIN}
	@${INSTALL_DATA} ${WRKSRC}/eepg.equiv.IT ${PREFIX}/etc/vdr/plugins/${PLUGIN}/eepg.equiv.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/eepg.equiv ]; then \
	    ${INSTALL_DATA} -o ${VDR_USER} -g ${VDR_GROUP} ${WRKSRC}/eepg.equiv.IT ${PREFIX}/etc/vdr/plugins/${PLUGIN}/eepg.equiv; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
