# ex:ts=8
# Ports collection Makefile for:	glens
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glens
PORTVERSION=	0.3
CATEGORIES=	science
MASTER_SITES=	http://virtual.theo.phys.ulg.ac.be/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libglui.a:${PORTSDIR}/devel/glui

USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS} -I${X11BASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -lstdc++"
CONFIGURE_ARGS=	--with-glui=${X11BASE}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/cfg ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
