# ex:ts=8
# Ports collection makefile for:	wxbasic
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wxbasic
PORTVERSION=	0.52
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	wxsource-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk

USE_MESA=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.unx
USE_GMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		-lglut -lGL -lGLU -lwx_gtk_gl ${PTHREAD_LIBS}
MAKE_ENV=	CXXFLAGS="${CXXFLAGS}" LIBS="${LIBS}"

post-patch:
	@${PERL} -pi -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/core.c

pre-build:
	@(cd ${WRKSRC} ; \
	  ${MV} -f wxbasic.y tmp ; ${CAT} tmp | col -b > wxbasic.y ; \
	  bison -o y_tab.c wxbasic.y)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wxbasic ${PREFIX}/bin

.include <bsd.port.mk>
