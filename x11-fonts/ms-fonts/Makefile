# New ports collection makefile for:    ms-fonts
# Date created:         May 1, 2001
# Whom:                 mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	ms-fonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.microsoft.com/typography/downloads/ \
		http://www.asia.microsoft.com/typography/downloads/ \
		http://www.eu.microsoft.com/typography/downloads/
DISTFILES=	mtcom.exe verdana.exe georgia.exe webdings.exe trebuc.exe \
		comic.exe ariblk.exe impact.exe times.exe
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-oL
NO_WRKSUBDIR=	yes
INST_DIR=	share/${PORTNAME}
PLIST_SUB+=	INST_DIR="${INST_DIR}"
NO_PACKAGE=	EULA: may not be distributed for profit either on a standalone \
		basis or included as part of your own product.

# My impression is,  koi8-ru is what later became koi8-u,  but I've been
# wrong a few times in the past. Let me  know, it happened  again. Also,
# there may be more charset translations needed. -mi
do-build:
	${PREFIX}/bin/ttmkfdir -d ${WRKDIR} | ${SED} s/koi8-ru/koi8-u/ \
		> ${WRKDIR}/fonts.dir

do-install:
	${MKDIR} "${PREFIX}/${INST_DIR}"
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${WRKDIR}/fonts.dir "${PREFIX}/${INST_DIR}"
	${TR} -d \\015 < ${WRKDIR}/readme.txt > "${PREFIX}/${INST_DIR}/eula.txt"
	${LN} -s fonts.dir "${PREFIX}/${INST_DIR}/fonts.scale"

post-install:
	@${SED} 's%/usr/local%${PREFIX}%g' < ${DESCR}

.include <bsd.port.mk>
