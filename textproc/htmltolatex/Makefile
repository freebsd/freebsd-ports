# ex:ts=8
# New ports collection makefile for:	htmltolatex
# Date created:			Jan 19, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	htmltolatex
PORTVERSION=	1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.ukc.mirror.ac.uk/sites/ftp.freebsd.org/pub/FreeBSD/ports/distfiles/ \
		http://people.FreeBSD.org/~foxfair/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML to LaTeX to PDF Converter

LIB_DEPENDS=	Magick.6:${PORTSDIR}/graphics/ImageMagick

USE_BISON=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	CXX="${CXX}" \
		CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -DUNIX"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/h2l ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/nmr.tex ${DATADIR}

.include <bsd.port.post.mk>
