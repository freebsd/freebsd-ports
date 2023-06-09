PORTNAME=	NunniMCAX
PORTVERSION=	1.4.1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C, non validating XML parser with SAX-like API
WWW=		https://sourceforge.net/projects/nunnimcax/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		uidfix
USE_LDCONFIG=	YES

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	SHLIB_MAJOR=${SHLIB_MAJOR}

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

SHLIB_MAJOR=	2

.include <bsd.port.options.mk>

.if defined(NOPROFILE) || defined(NO_PROFILE) || ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079 )
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

.include <bsd.port.mk>
