# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmu
DISTVERSION=	1.901b
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/thdltools/TibetanMachineFont/TMU_${DISTVERSION}
DISTFILES=	gpl.txt \
		TibMachUni-${DISTVERSION}.ttf
DIST_SUBDIR=	tmu

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Free Tibetan Machine Uni font

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/gpl.txt

USES=		fonts

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	${FONTSDIR}/tmu.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TibMachUni-${DISTVERSION}.ttf \
		${STAGEDIR}${FONTSDIR}/tmu.ttf

.include <bsd.port.mk>
