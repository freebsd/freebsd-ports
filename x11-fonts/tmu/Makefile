# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tmu
DISTVERSION=	1.901b
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/thdltools/TibetanMachineFont/TMU_${DISTVERSION}
DISTFILES=	TibMachUni-${DISTVERSION}.ttf
DIST_SUBDIR=	tmu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Tibetan Machine Uni font

LICENSE=	GPLv3	# gpl.txt located at SF site

USES=		fonts
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	${FONTSDIR}/tmu.ttf

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TibMachUni-${DISTVERSION}.ttf \
		${STAGEDIR}${FONTSDIR}/tmu.ttf

.include <bsd.port.mk>
