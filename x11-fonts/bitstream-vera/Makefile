# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitstream-vera
PORTVERSION=	1.10
PORTREVISION=	7
CATEGORIES=	x11-fonts
MASTER_SITES=	GNOME/sources/ttf-${PORTNAME}/${PORTVERSION}
DISTNAME=	ttf-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Bitstream Vera TrueType font collection

LICENSE=	BITSTREAM_VERA
LICENSE_NAME=	Bitstream Vera Fonts Copyright
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		fonts tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.TXT ${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASENOTES.TXT ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
