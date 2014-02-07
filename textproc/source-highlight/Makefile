# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	source-highlight
PORTVERSION=	3.1.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	src-highlite

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags
LIB_DEPENDS=	libboost_regex.so:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

USES=	gmake pathfix
USE_LDCONFIG=	yes

INFO=	source-highlight source-highlight-lib

OPTIONS_DEFINE=	BASH DOCS EXAMPLES

BROKEN_sparc64=	Does not compile with GCC 4.2

BASH_RUN_DEPENDS=	${LOCALBASE}/etc/bash_completion:${PORTSDIR}/shells/bash-completion
BASH_CONFIGURE_WITH=	--with-bash-completion

OPTIONS_SUB=	yes

test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} ${MAKE_ARGS} check)

.include <bsd.port.mk>
