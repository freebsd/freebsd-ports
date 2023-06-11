PORTNAME=	pkg-provides
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
PORTREVISION=	2
CATEGORIES=	ports-mgmt

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Pkg plugin for querying which package provides a particular file
WWW=		https://github.com/rosorio/pkg-provides

LICENSE=	BSD2CLAUSE BSD3CLAUSE BSD4CLAUSE
LICENSE_COMB=	multi

NOT_FOR_ARCHS=	armv6 mips mips64

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	libpcre.so:devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	rosorio
GH_TAGNAME=	2b0ed4f81b0c6c7ee6b53438401724fe4153630c
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE}

PLIST_FILES=	lib/pkg/provides.so \
		man/man8/pkg-provides.8.gz

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/pkg/
	${INSTALL_LIB} ${WRKSRC}/provides.so ${STAGEDIR}${LOCALBASE}/lib/pkg/
	${INSTALL_MAN} ${WRKSRC}/pkg-provides.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
