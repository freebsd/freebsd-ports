# New ports collection makefile for: English PK fonts
# Version required:	?
# Date created:		16 Mar 1996
# Whom:			Hideaki Ohmon <ohmon@sfc.keio.ac.jp>
#
# $Id$
#

DISTNAME=	pkfonts
PKGNAME=	pkfonts${RESOLUTION}-1.0
CATEGORIES+=	print
MASTER_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/TeX/fonts/
DISTFILES=	pk${RESOLUTION}.tar.gz
# see below for RESOLUTION definition

MAINTAINER=	ohmon@sfc.keio.ac.jp

DIST_SUBDIR=	pkfonts
EXTRACT_CMD=	/usr/bin/true # extracted directly in install target
NO_BUILD=	yes

.if !defined(RESOLUTION)
RESOLUTION=     300
RESOLUTION_UNSPECIFIED=	yes
.else
.if ${RESOLUTION} != 118 && ${RESOLUTION} != 240 && \
	${RESOLUTION} != 300 && ${RESOLUTION} != 400
RESOLUTION_INVALID=	yes
.endif
.endif

pre-fetch:
.if defined(RESOLUTION_UNSPECIFIED)
	@echo "Using ${RESOLUTION}dpi English PK fonts."
	@echo "Set the environment variable RESOLUTION if you want"
	@echo "it to use other resolutions."
	@echo "Possible values are: 118, 240, 300 (default) and 400."
.elif defined(RESOLUTION_INVALID)
	@echo "Error: invalid value for RESOLUTION: \"${RESOLUTION}\"" 
	@echo "Possible values are: 118, 240, 300 (default) and 400." 
	@/usr/bin/false
.endif

do-install:
	mkdir -p ${PREFIX}/lib/fonts
	tar -C ${PREFIX}/lib/fonts -xzf ${DISTDIR}/${DISTFILES}
	@cp ${PKGDIR}/${RESOLUTION}.list ${PKGDIR}/PLIST 

.include <bsd.port.mk>
