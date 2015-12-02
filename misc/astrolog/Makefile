# Created by: faulkner@cactus.org
# $FreeBSD$

PORTNAME=	astrolog
PORTVERSION=	5.41g
PORTREVISION=	3
CATEGORIES=	misc astro
MASTER_SITES=	ftp://ftp.astro.com/pub/swisseph/ephe/archive_gzip/:ephe \
		ftp://ftp.astro.com/pub/swisseph/:libswe \
		http://astrolog.offline.ee/astrolog/changed/:dist
DISTFILES=	a541gsrc.tar.gz:dist ${EPHE} \
		swe_unix_src_2.02.01.tar.gz:libswe

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astrology program for X11 and alpha-numeric terminals

# Swiss Ephemeris GPLv2 licensed, see
# http://www.astro.com/ftp/swisseph/LICENSE.TXT
LICENSE=	GPLv2 # (or later)

EPHE=		sweph_00.tar.gz:ephe sweph_06.tar.gz:ephe \
		sweph_12.tar.gz:ephe sweph_18.tar.gz:ephe \
		sweph_24.tar.gz:ephe sweph_30.tar.gz:ephe \
		sweph_36.tar.gz:ephe sweph_42.tar.gz:ephe \
		sweph_48.tar.gz:ephe swephm06.tar.gz:ephe \
		swephm12.tar.gz:ephe swephm18.tar.gz:ephe \
		swephm24.tar.gz:ephe swephm30.tar.gz:ephe \
		swephm36.tar.gz:ephe swephm42.tar.gz:ephe \
		swephm48.tar.gz:ephe swephm54.tar.gz:ephe

DIST_SUBDIR=	astrolog
ALL_TARGET=	astrolog
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

PORTDOCS=	helpfile.540 readme.541 changes.txt

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
MAKE_ARGS=	-DX11
.endif

post-extract:
	${RM} ${WRKSRC}/swe[a-z]*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/astrolog
	cd ${WRKSRC} && \
		${INSTALL_DATA} fixstars.ast *.se1 ${STAGEDIR}${PREFIX}/lib/astrolog
	cd ${WRKSRC}; \
		${INSTALL_DATA} astrolog.dat ${STAGEDIR}${PREFIX}/lib/astrolog/astrolog.dat-dist
	cd ${WRKSRC} && ${INSTALL_PROGRAM} astrolog ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} "See the file ${PREFIX}/share/doc/astrolog/helpfile.540 for help"
	@${ECHO_MSG} "and tune ${PREFIX}/lib/astrolog/astrolog.dat"

.include <bsd.port.mk>
