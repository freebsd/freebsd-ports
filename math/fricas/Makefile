PORTNAME=	fricas
DISTVERSION=	1.3.8
DISTVERSIONSUFFIX=	-full
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced computer algebra system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/LICENSE.AXIOM

BROKEN_i386=	build fails, reported to ML

BUILD_DEPENDS=	sbcl:lang/sbcl

USES=		autoreconf gmake tar:bz2 xorg
USE_XORG=	ice sm x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=sbcl

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

STRIP=		#these binaries fail if stripped

PLIST_SUB=	HOST_ARCH="${CONFIGURE_TARGET}"

.include <bsd.port.mk>
