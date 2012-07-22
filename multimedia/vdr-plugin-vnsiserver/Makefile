# New ports collection makefile for:	vdr-plugin-vnsiserver
# Date created:		Tue Oct  5 21:13:30 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-vnsiserver
PORTVERSION=	0.0.2s20100808.0952
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	http://ppa.launchpad.net/yavdr/testing-vdr/ubuntu/pool/main/v/vdr-plugin-vnsiserver/ \
		LOCAL/nox/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION:S/s20/+svn20/}${DISTVERSIONSUFFIX}.orig

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - VNSI server plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION:S/s20/+svn20/}${DISTVERSIONSUFFIX}

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
