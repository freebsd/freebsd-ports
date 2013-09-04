# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/Hunspell/${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Improved spell-checker for Hungarian and other languages

LICENSE=	GPLv2 LGPL21 MPL
LICENSE_COMB=	dual

CONFIGURE_ARGS=	--disable-nls ${ICONV_CONFIGURE_ARG} --with-readline --with-ui
GNU_CONFIGURE=	yes
USES=		pathfix iconv ncurses readline
USE_LDCONFIG=	yes

MANLANG=	"" hu
MAN1_EN=	hunspell.1 hunzip.1 hzip.1
MAN1_HU=	hunspell.1
MAN3_EN=	hunspell.3
MAN4_EN=	hunspell.4
MAN4_HU=	hunspell.4

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/tools/hunspell.cxx

.include <bsd.port.mk>
