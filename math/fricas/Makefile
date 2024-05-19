PORTNAME=	fricas
DISTVERSION=	1.3.9
DISTVERSIONSUFFIX=	-full
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced computer algebra system
WWW=		https://fricas.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/LICENSE.AXIOM

BUILD_DEPENDS=	sbcl:lang/sbcl
RUN_DEPENDS=	rlwrap:devel/rlwrap

USES=		autoreconf gmake tar:bz2 xorg
USE_XORG=	ice sm x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp="sbcl --dynamic-space-size 2048"

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

STRIP=		#these binaries fail if stripped

PLIST_SUB=	HOST_ARCH="${CONFIGURE_TARGET}"

.include <bsd.port.mk>
