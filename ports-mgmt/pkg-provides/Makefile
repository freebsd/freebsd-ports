# $FreeBSD$

PORTNAME=	pkg-provides
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	ports-mgmt

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Pkg plugin for querying which package provides a particular file

LICENSE=	BSD2CLAUSE

NOT_FOR_ARCHS=	armv6 mips mips64

LIB_DEPENDS=	libpcre.so:devel/pcre
BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash

USE_LDCONFIG=	yes
USE_GITHUB=	yes

SUB_LIST=	LOCALBASE=${LOCALBASE}

GH_ACCOUNT=	rosorio
GH_TAGNAME=	c5bfc75

PLIST_FILES=	lib/pkg/provides.so man/man8/pkg-provides.8.gz

do-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/pkg/
	${INSTALL_LIB} ${WRKSRC}/provides.so ${STAGEDIR}${LOCALBASE}/lib/pkg/
	${INSTALL_MAN} ${WRKSRC}/pkg-provides.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
