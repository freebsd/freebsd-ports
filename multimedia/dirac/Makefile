# New ports collection makefile for:	dirac
# Date created:		11 May 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dirac
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source video codec from the BBC

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack gnometarget
USE_GCC=	3.4
INSTALLS_SHLIB=	yes

CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include
CONFIGURE_ENV+=	HAVE_LATEX=false HAVE_DVIPDFM=false

.if defined(NOPORTDOCS)
CONFIGURE_ENV+=	HAVE_DOXYGEN=false HAVE_DOT=false
.else
BUILD_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
