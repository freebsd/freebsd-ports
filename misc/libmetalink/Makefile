# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmetalink
PORTVERSION=	0.1.2
CATEGORIES=	misc
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Metalink library written in C language

LICENSE=	MIT

OPTIONS_DEFINE=	EXAMPLES TEST
OPTIONS_SINGLE=	XML
OPTIONS_SINGLE_XML=	EXPAT LIBXML2
OPTIONS_DEFAULT=EXPAT

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USES=		pathfix tar:bzip2

PORTEXAMPLES=	LibO_3.5.4_Win_x86_install_multi.msi.meta4 \
		metalinkcat.c \
		ubuntu-12.04-server-amd64.metalink

EXPAT_CONFIGURE_WITH=	libexpat
EXPAT_CPPFLAGS=		-I${LOCALBASE}/include
EXPAT_LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2
LIBXML2_CONFIGURE_WITH=	libxml2
LIBXML2_CPPFLAGS=	-I${LOCALBASE}/include/libxml2
LIBXML2_USE=		GNOME=libxml2
TEST_BUILD_DEPENDS=	cunit>=2.1:${PORTSDIR}/devel/cunit
TEST_CONFIGURE_ENV=	CUNIT_CFLAGS=-I${LOCALBASE}/include CUNIT_LIBS="-L${LOCALBASE}/lib -lcunit -L${LIBDIR} -lncurses"

post-build:
	@${STRIP_CMD} ${WRKSRC}/lib/.libs/libmetalink.so.3

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/doc/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
