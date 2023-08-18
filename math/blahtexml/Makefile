PORTNAME=	blahtexml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TeX to MathML converter designed with MediaWiki in mind
WWW=		http://gva.noekeon.org/blahtexml/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libxerces-c.so:textproc/xerces-c3

USES=		gmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	gvanas

MAKEFILE=	makefile
MAKE_ARGS=	CFLAGS="${CFLAGS}"

ALL_TARGET=	blahtexml-linux

LDFLAGS+=	-liconv

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
USES+=	llvm:max=15
CC=	clang${LLVM_VERSION}
CPP=	clang-cpp${LLVM_VERSION}
CXX=	clang++${LLVM_VERSION}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
