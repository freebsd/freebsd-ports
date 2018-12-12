# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-epgsearch
PORTVERSION=	1.0.1s20120322
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	http://winni.vdr-developer.org/epgsearch/downloads/beta/:beta \
		LOCAL/nox/:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - EPG search plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libtre.so:textproc/libtre

USES=		pkgconfig tar:bzip2
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/vdr-plugin-${PLUGIN}
MAKE_ARGS=	INCLUDES="-I${LOCALBASE}/include -I${LOCALBASE}/include/vdr -I${WRKSRC}"

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS NLS

.include "${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} -e 's/^#\(HAVE_PCREPOSIX=\)/\1/;' \
		-e 's/^#\(HAVE_LIBTRE=\)/\1/;' \
		${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
