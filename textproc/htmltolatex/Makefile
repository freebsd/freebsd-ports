# ex:ts=8
# New ports collection makefile for:	htmltolatex
# Date created:			Jan 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	htmltolatex
PORTVERSION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://crydee.sai.msu.ru/zeus/unix/WWW/tools/converters/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Magick:${PORTSDIR}/graphics/ImageMagick

USE_REINPLACE=	yes
USE_BISON=	yes
MAKEFILE=	GNUmakefile
CXXFLAGS+=	-I${LOCALBASE}/include -DUNIX
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^CXXFLAGS,#CXXFLAGS,g ; \
		s,^CXX,#CXX,g" ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/h2l ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/nmr.tex ${DATADIR}

.include <bsd.port.mk>
