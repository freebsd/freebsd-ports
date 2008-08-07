# ex:ts=8
# Ports collection makefile for:	libtre
# Date created:			Oct 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libtre
PORTVERSION=	0.7.5
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://laurikari.net/tre/ \
		LOCAL/jkoshy
DISTNAME=	tre-${PORTVERSION}

MAINTAINER=	bf2006a@yahoo.com
COMMENT=	A lightweight fully POSIX compliant regexp matching library

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=	--enable-static
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	NLS "native language support" off \
		OPTIMIZED_CFLAGS "append optimization flags to CFLAGS" off

MAN1=	tre_agrep.1

.include <bsd.port.pre.mk>

.if defined(WITH_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations \
		-fforce-mem -fforce-addr -O3
.endif

post-patch:
	${MV} ${WRKSRC}/doc/agrep.1.in ${WRKSRC}/doc/tre_agrep.1.in
	${REINPLACE_CMD} -e 's;agrep\.1;tre_agrep\.1;g' ${WRKSRC}/configure \
	${WRKSRC}/tre.spec.in ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's;agrep;tre_agrep;g' ${WRKSRC}/tests/agrep/*.ok

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in tre-api.html tre-syntax.html
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

regression-test: build
	@(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} check )

.include <bsd.port.post.mk>
