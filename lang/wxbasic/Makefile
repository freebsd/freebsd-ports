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

PORTCOMMENT=	A cross-platform GUI Basic interpreter

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel

NO_WRKSUBDIR=	yes

USE_REINPLACE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile.unx
CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		-lglut -lGL -lGLU -lwx_gtk_gl ${PTHREAD_LIBS}
MAKE_ENV=	CXXFLAGS="${CXXFLAGS}" LIBS="${LIBS}"

post-patch:
	@${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g" ${WRKSRC}/core.c

pre-build:
	@(cd ${WRKSRC} ; \
	  ${MV} -f wxbasic.y tmp ; ${CAT} tmp | col -b > wxbasic.y ; \
	  bison -o y_tab.c wxbasic.y)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wxbasic ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.wx ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
