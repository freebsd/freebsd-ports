# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmetalink
PORTVERSION=	0.1.3
CATEGORIES=	misc
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${PORTNAME}-${PORTVERSION}/+download/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Metalink library written in C language

LICENSE=	MIT

OPTIONS_DEFINE=	EXAMPLES TEST
OPTIONS_SINGLE=	XML
OPTIONS_SINGLE_XML=	EXPAT LIBXML2
OPTIONS_DEFAULT=EXPAT

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		libtool localbase pathfix tar:xz

PORTEXAMPLES=	LibO_3.5.4_Win_x86_install_multi.msi.meta4 \
		metalinkcat.c \
		ubuntu-12.04-server-amd64.metalink

EXPAT_CONFIGURE_WITH=	libexpat
EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
LIBXML2_CONFIGURE_WITH=	libxml2
LIBXML2_CPPFLAGS=	-I${LOCALBASE}/include/libxml2
LIBXML2_USE=		GNOME=libxml2
TEST_BUILD_DEPENDS=	cunit>=2.1:devel/cunit

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/doc/examples/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
