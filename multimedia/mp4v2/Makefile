PORTNAME=	mp4v2
PORTVERSION=	2.1.3
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/enzo1982/mp4v2/releases/download/v${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library and tools to read, create, and modify mp4 files
WWW=		http://mp4v2.org/

LICENSE=	MPL11

USES=		compiler:features cpe gmake libtool tar:bzip2

CPE_VENDOR=	mp4v2_project

MAKEFILE=	GNUmakefile
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	"FOUND_HELP2MAN=no"
CXXFLAGS+=	${COMPILER_FEATURES:Mc++11:C/.+/-Wno-error=narrowing/}

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
CONFIGURE_ARGS=	--disable-gch
.endif

.include <bsd.port.post.mk>
