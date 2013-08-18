# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-vnsiserver
PORTVERSION=	12.0
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freebsd.org/~decke/distfiles/
DISTNAME=	xbmc-pvr-addons-${PORTVERSION}-Frodo

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - VNSI server plugin (Frodo)

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/xbmc-pvr-addons-${PORTVERSION}-Frodo/addons/pvr.vdr.vnsi/${PORTNAME}

MAKE_ARGS+=	LIBDIR=${WRKDIR}/lib \
		LOCDIR=${WRKDIR}/locale \
		VDRSRC=${LOCALBASE}/include/vdr \
		INCLUDES=-I${LOCALBASE}/include

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
