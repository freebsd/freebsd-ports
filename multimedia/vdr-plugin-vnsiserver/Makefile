# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-vnsiserver
PORTVERSION=	12.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freebsd.org/~decke/distfiles/
DISTNAME=	xbmc-pvr-addons-${PORTVERSION}-20140104

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - VNSI server plugin

USE_GITHUB=	yes
GH_ACCOUNT=	opdenkamp
GH_PROJECT=	xbmc-pvr-addons
GH_COMMIT=	9021115
GH_TAGNAME=	9021115

USES=		pkgconfig
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/opdenkamp-xbmc-pvr-addons-${GH_COMMIT}/addons/pvr.vdr.vnsi/${PORTNAME}

MAKE_ARGS+=	LIBDIR=${WRKDIR}/lib \
		LOCDIR=${WRKDIR}/locale \
		VDRSRC=${LOCALBASE}/include/vdr \
		INCLUDES=-I${LOCALBASE}/include

NO_STAGE=	yes

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install:
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}5
	@${INSTALL_DATA} ${WRKSRC}/${PLUGIN}/allowed_hosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}5/allowed_hosts.conf.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}5/allowed_hosts.conf ]; then \
	    ${INSTALL_DATA} -o ${VDR_USER} -g ${VDR_GROUP} ${WRKSRC}/${PLUGIN}/allowed_hosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}5; \
	fi
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
