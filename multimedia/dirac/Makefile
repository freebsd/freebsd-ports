# New ports collection makefile for:	dirac
# Date created:		11 May 2004
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dirac
PORTVERSION=	0.5.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open source video codec from the BBC

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack gnometarget
USE_GCC=	3.4
PORTDOCS=	README

CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
