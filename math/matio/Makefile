# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	matio
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for reading/writing Matlab files

GNU_CONFIGURE=	yes
USES=		pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	FORTRAN
FORTRAN_DESC=	Build Fortran bindings

CONFIGURE_ARGS=	--enable-shared

PLIST_FILES= 	include/matio.h \
		include/matioConfig.h \
		lib/libmatio.a \
		lib/libmatio.la \
		lib/libmatio.so \
		lib/libmatio.so.1 \
		libdata/pkgconfig/matio.pc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFORTRAN}
USES+=		fortran

CONFIGURE_ARGS+=	--enable-fortran
CONFIGURE_ENV+=	FCFLAGS="${FFLAGS}"

PLIST_FILES+=	include/matio.mod

MAKE_JOBS_UNSAFE=yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/AM_LDFLAGS = /s/$$/ -version-info 1/'	\
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
