# New ports collection makefile for:	vdr-plugin-epgsearch
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-epgsearch
PORTVERSION=	1.0.1s20120322
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://winni.vdr-developer.org/epgsearch/downloads/beta/:beta \
		LOCAL/nox/:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - EPG search plugin

LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre \
		tre:${PORTSDIR}/textproc/libtre

USE_BZIP2=	yes
PATCH_STRIP=	-p1
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/vdr-plugin-${PLUGIN}
MAKE_ARGS+=	INCLUDES="-I$(LOCALBASE)/include -I$(LOCALBASE)/include/vdr -I${WRKSRC}"

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} 's/^#\(HAVE_PCREPOSIX=\)/\1/;'\\
		's/^#\(HAVE_LIBTRE=\)/\1/;' \
		${WRKSRC}/Makefile

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
