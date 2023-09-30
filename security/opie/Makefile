PORTNAME=	opie
PORTVERSION=	1.20230501
CATEGORIES=	security

MAINTAINER=	des@FreeBSD.org
COMMENT=	One-time Passwords In Everything

LICENSE=	TINV2 BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_TINV2=	The Inner Net License, Version 2
LICENSE_FILE_TINV2=	${WRKSRC}/opie/License.TIN
LICENSE_PERMS_TINV2=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	opie

MAKE_ARGS=	BINDIR=${PREFIX}/bin \
		INCLUDEDIR=${PREFIX}/include \
		LIBDIR=${PREFIX}/lib \
		MANDIR=${MANPREFIX}/man/man

IGNORE_FreeBSD_13=	FreeBSD 13 has OPIE in base

.include <bsd.port.mk>
