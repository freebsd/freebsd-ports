# New ports collection makefile for:	vdr-plugin-xvdr
# Date created:		Sat Oct  8 17:45:22 CEST 2011
# Whom:			Juergen Lock <nox@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-xvdr
PORTVERSION=	0.9.5
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	LOCAL/nox/
DISTNAME=	pipelka-${PORTNAME}-xvdr-${PORTVERSION}-0-g${GITHASH}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - XVDR server plugin

GITHASH=	e4cab47
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/pipelka-${PORTNAME}-${GITHASH}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install:
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}
	@${INSTALL_DATA} ${WRKSRC}/${PLUGIN}/allowed_hosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf ]; then \
	    ${INSTALL_DATA} -o ${VDR_USER} -g ${VDR_GROUP} ${WRKSRC}/${PLUGIN}/allowed_hosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
