# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	source-highlight
PORTVERSION=	3.1.6
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GNU/src-highlite

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	exctags:devel/ctags
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

USES=		gmake pathfix libtool
USE_LDCONFIG=	yes

INFO=	source-highlight source-highlight-lib

OPTIONS_DEFINE=	BASH DOCS EXAMPLES

BROKEN_sparc64=	Does not compile with GCC 4.2

BASH_RUN_DEPENDS=	${LOCALBASE}/etc/bash_completion:shells/bash-completion
BASH_CONFIGURE_WITH=	--with-bash-completion

OPTIONS_SUB=	yes

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>
