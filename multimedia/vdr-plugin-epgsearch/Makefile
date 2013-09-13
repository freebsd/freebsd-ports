# Created by: Juergen Lock <nox@freebsd.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-epgsearch
PORTVERSION=	1.0.1s20120322
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://winni.vdr-developer.org/epgsearch/downloads/beta/:beta \
		LOCAL/nox/:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - EPG search plugin

LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre \
		tre:${PORTSDIR}/textproc/libtre

USES=		pkgconfig
USE_BZIP2=	yes
PATCH_STRIP=	-p1
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/vdr-plugin-${PLUGIN}
MAKE_ARGS+=	INCLUDES="-I$(LOCALBASE)/include -I$(LOCALBASE)/include/vdr -I${WRKSRC}"

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} -e 's/^#\(HAVE_PCREPOSIX=\)/\1/;' \
		-e 's/^#\(HAVE_LIBTRE=\)/\1/;' \
		${WRKSRC}/Makefile

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
