# New ports collection makefile for:	pspell
# Date created:				13th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pspell
PORTVERSION= 	0.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0//}

MAINTAINER=	ports@FreeBSD.org

USE_NEWGCC=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure modules/configure libltdl/configure
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS} -I${WRKSRC}" \
		CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
MAKE_ARGS+=	NOPORTDOCS=${NOPORTDOCS}
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS=	--enable-doc-dir=${PREFIX}/share/doc/pspell
.endif
USE_GMAKE=	yes

.include <bsd.port.mk>
