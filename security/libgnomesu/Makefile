# New ports collection makefile for:	libgnomesu
# Date created:				12 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgnomesu
PORTVERSION=	0.9.6
CATEGORIES=	security gnome
MASTER_SITES=	http://members1.chello.nl/~h.lai/libgnomesu/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Library for su integration with GNOME apps

USE_X_PREFIX=	yes
USE_GETOPT_LONG=yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

CONFLICTS=	gnomesu-*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/api.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/libgnomesu.css ${DOCSDIR}
.endif

.include <bsd.port.mk>
