# $FreeBSD$

PORTNAME=	siesta
DISTVERSION=	4.0.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${DISTVERSION:R}/${DISTVERSION}/+download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program to perform efficient electronic structure calculations

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../Src/configure
ALL_TARGET=	default

WRKSRC_SUBDIR=	Obj

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} ../Src/obj_setup.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
