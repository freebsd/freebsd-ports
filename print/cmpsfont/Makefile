# New ports collection makefile for:	cmps
# Date created:		11 September 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	cmpsfont
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://ftp.ams.org/pub/tex/psfonts/cm/
DISTNAME=	cmps
EXTRACT_SUFX=	-unix.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Computer Modern PostScript Fonts (Adobe Type 1 format)

BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/cmpsfont

FONTSDIR=	share/fonts/${PORTNAME}

do-build:
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog)

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}/afm
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/${FONTSDIR}/afm
	${MKDIR} ${PREFIX}/${FONTSDIR}/pfb
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${PREFIX}/${FONTSDIR}/pfb
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/cmsample.tex ${PREFIX}/${FONTSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
