# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	source-highlight
PORTVERSION=	3.1.6
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	GNU/src-highlite

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	exctags:devel/ctags
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

BROKEN_powerpc64=	Does not build
BROKEN_sparc64=	Does not compile with GCC 4.2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash-completion

INSTALL_TARGET=	install-strip

USES=		gmake pathfix libtool localbase
USE_LDCONFIG=	yes

INFO=	source-highlight source-highlight-lib

OPTIONS_DEFINE=	DOCS EXAMPLES

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>
