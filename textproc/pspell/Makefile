# New ports collection makefile for:	pspell
# Date created:				13th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pspell
PORTVERSION= 	0.11.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://download.sourceforge.net/pspell/
DISTNAME=	${PORTNAME}-.11.0.1

MAINTAINER=	ade@FreeBSD.org

USE_NEWGCC=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure modules/configure
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS} -I${WRKSRC}"
MAKE_ARGS+=	NOPORTDOCS=${NOPORTDOCS}
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS=	--enable-doc-dir=${PREFIX}/share/doc/pspell
.endif
USE_GMAKE=	yes

.include <bsd.port.mk>
