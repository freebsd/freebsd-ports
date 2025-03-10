PORTNAME=	num
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	math
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Legacy library for arbitrary-precision arithmetic
WWW=		https://github.com/ocaml/num

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ocaml
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml

MAKE_ENV=	OCAMLFIND_DESTDIR="${STAGEDIR}${OCAMLFIND_DESTDIR}"
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	test

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LLD_UNSAFE=	yes
.endif

.include <bsd.port.mk>
