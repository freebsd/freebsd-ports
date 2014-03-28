# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-wirbelscan
PORTVERSION=	0.0.7
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/wirbelscan/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - wirbelscan plugin

USES=		tar:tgz
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/*.c ${WRKSRC}/*.h

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
