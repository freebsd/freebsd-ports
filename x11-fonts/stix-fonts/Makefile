# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	stixfonts
PORTVERSION=	1.1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	STIXv${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A comprehensive set of fonts for scientific and engineering purposes

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"	\
		FCCACHE='${FCCACHE}'

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	stix
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir
FCCACHE=	${LOCALBASE}/bin/fc-cache -f -v

.if !defined(NOPORTDOCS)
PORTDOCS=	STIXv${PORTVERSION}.pdf
.endif

NO_STAGE=	yes
do-build:
	${MKDIR} ${WRKDIR}/build
.for group in STIX-General STIX-Word
	${CP} ${WRKSRC}/Fonts/${group}/*.otf ${WRKDIR}/build
.endfor
	cd ${WRKDIR}/build && ${MKFONTSCL_CMD}
	${REINPLACE_CMD} -e 's|-misc-|-stix-|' ${WRKDIR}/build/fonts.scale
	cd ${WRKDIR}/build && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKDIR}/build && ${INSTALL_DATA} fonts.dir fonts.scale *.otf ${FONTDIR}
	cd ${FONTDIR} && ${MKFONTDIR_CMD}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE} ${FONTDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
