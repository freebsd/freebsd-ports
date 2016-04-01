# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.7.20050716
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

DISTNAME=	ct17a15

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Drawing organic molecules easily and store them (developer version)

LIB_DEPENDS=	libEMF.so:graphics/libemf
RUN_DEPENDS=	transfig:print/transfig

WRKSRC=		${WRKDIR}/${PORTNAME}-1.7alpha15/
USE_GNOME=	gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig tar:tgz
CONFIGURE_ARGS=	--enable-emf=yes
PKGNAMESUFFIX=	-devel
MAKE_ARGS+=	MAKE=${MAKE_CMD}
MAKE_JOBS_UNSAFE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libEMF
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++//' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^SYS_LIBRARIES =/s/$$/ -lX11/' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
