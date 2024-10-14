PORTNAME=	fricas
DISTVERSION=	1.3.10
DISTVERSIONSUFFIX=	-full
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced computer algebra system
WWW=		https://fricas.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/LICENSE.AXIOM

BROKEN_i386=	fails to configure: mmap: Cannot allocate memory

BUILD_DEPENDS=	sbcl:lang/sbcl
LIB_DEPENDS=	libzstd.so:archivers/zstd
RUN_DEPENDS=	rlwrap:devel/rlwrap

USES=		autoreconf gmake tar:bz2 xorg
USE_XORG=	ice sm x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp="sbcl --dynamic-space-size 3072"

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

STRIP=		#these binaries fail if stripped

PLIST_SUB=	HOST_ARCH="${CONFIGURE_TARGET}"

.include <bsd.port.mk>
