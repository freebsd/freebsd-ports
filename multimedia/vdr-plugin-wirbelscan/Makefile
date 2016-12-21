# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-wirbelscan
PORTVERSION=	0.0.7
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://wirbel.htpc-forum.de/wirbelscan/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - wirbelscan plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix tar:tgz
DOS2UNIX_FILES=	scanner.c
PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

PORTDOCS=	README HISTORY

OPTIONS_DEFINE=	DOCS NLS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} -f ${FILESDIR}/types.sed ${WRKSRC}/*.c ${WRKSRC}/*.h

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
