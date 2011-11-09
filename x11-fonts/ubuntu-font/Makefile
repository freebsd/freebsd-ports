# New ports collection makefile for:	ubuntu-font
# Date created:		09 November 2011
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ubuntu-font
PORTVERSION=	0.80
CATEGORIES=	x11-fonts
MASTER_SITES=	http://font.ubuntu.com/download/

DISTNAME=	${PORTNAME}-family-${PORTVERSION}

MAINTAINER=	kevloFreeBSD.org
COMMENT=	Ubuntu Font Family

LICENSE=	UFL
LICENSE_FILE=	${WRKSRC}/LICENCE.txt
LICENSE_NAME=	Ubuntu Font License (UFL)
LICENSE_PERMS=	auto-accept

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontscale
	cd ${WRKSRC} && ${LOCALBASE}/bin/mkfontdir

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt ${DOCSDIR}
.endif
	${MKDIR} ${FONTSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} fonts.dir fonts.scale *.ttf ${FONTSDIR}

.include <bsd.port.mk>
