# Created by: bf@FreeBSD.org
# $FreeBSD$

PORTNAME=	reflex
PORTVERSION=	20191123
CATEGORIES=	textproc
MASTER_SITES=	https://invisible-mirror.net/archives/reflex/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Relocalizable fast lexical scanner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz

CONFIGURE_ENV=	YACC="${YACC}"
GNU_CONFIGURE=	yes
TEST_TARGET=	bigcheck

.include <bsd.port.mk>
