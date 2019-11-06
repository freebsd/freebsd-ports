# $FreeBSD$

PORTNAME=	fricas
DISTVERSION=	1.3.5
DISTVERSIONSUFFIX=	-full
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Advanced computer algebra system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license/LICENSE.AXIOM

BUILD_DEPENDS=	sbcl:lang/sbcl

USES=		autoreconf gmake tar:bz2 xorg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lisp=sbcl
USE_XORG=	ice sm x11 xpm

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

STRIP=		#these binaries fail if stripped

PLIST_SUB=	HOST_ARCH="${CONFIGURE_TARGET}"

.include <bsd.port.mk>
