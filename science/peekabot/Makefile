# New ports collection makefile for:	peekabot
# Date created:		21 June 2009
# Whom:			chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	peekabot
PORTVERSION=	0.7.2
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.7.x/ \
		http://distfiles.officialunix.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed real-time 3D visualization tool for robotics researchers

LIB_DEPENDS=	boost_regex.4:${PORTSDIR}/devel/boost-libs \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2\
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="`fltk-config --ldflags`" \
		CPPFLAGS="`fltk-config --cflags`"
USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
USE_GCC=	4.2+
.endif

.if ${ARCH} == "sparc64"
BROKEN=		does not compile with boost on sparc64
.endif

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/src/3rdparty/png++/io_base.hpp

.include <bsd.port.post.mk>
