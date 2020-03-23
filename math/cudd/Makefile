# $FreeBSD$

PORTNAME=	cudd
DISTVERSION=	3.0.0
CATEGORIES=	math
MASTER_SITES=	https://davidkebo.com/source/cudd_versions/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for the manipulation of Binary Decision Diagrams (BDDs), etc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

PLIST_FILES=	include/cudd.h \
		lib/libcudd-3.0.0.so.0 \
		lib/libcudd-3.0.0.so.0.0.0 \
		lib/libcudd.a \
		lib/libcudd.so

.include <bsd.port.mk>
