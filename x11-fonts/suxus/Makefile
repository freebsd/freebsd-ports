# $FreeBSD$

PORTNAME=	suxus
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://oldhome.schmorp.de/marc/data/ \
		http://www.atarininja.org/distfiles/
DISTFILES=	${PORTNAME}-iso-8859-1.bdf.gz fonts.alias
DIST_SUBDIR=	suxus

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	An x11 font designed to be small yet easily read

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

SUB_FILES=	pkg-message
USE_XORG=	x11

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-iso-8859-1.bdf.gz ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/fonts.alias ${WRKSRC}
	@${EXTRACT_CMD} -d  ${WRKSRC}/${PORTNAME}-iso-8859-1.bdf.gz

do-build:
	${PREFIX}/bin/bdftopcf -t ${WRKSRC}/suxus-iso-8859-1.bdf | ${EXTRACT_CMD} > ${WRKSRC}/suxus-iso-8859-1.pcf.gz
	${PREFIX}/bin/mkfontdir ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/local/suxus
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${PREFIX}/lib/X11/fonts/local/suxus
	@${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/lib/X11/fonts/local/suxus
	@${INSTALL_DATA} ${WRKSRC}/fonts.alias ${PREFIX}/lib/X11/fonts/local/suxus

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
