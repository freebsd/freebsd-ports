# ex:ts=8
# Ports collection Makefile for:	glens
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glens
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://virtual.theo.phys.ulg.ac.be/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL gravitational lens simulator

BUILD_DEPENDS=	${X11BASE}/lib/libglui.a:${PORTSDIR}/devel/glui

USE_REINPLACE=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-glui=${X11BASE}

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O6||g ; \
		s|-malign-double||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}/cfg
	${INSTALL_DATA} ${WRKSRC}/cfg/*.cgf ${EXAMPLESDIR}/cfg
.endif

.include <bsd.port.post.mk>
