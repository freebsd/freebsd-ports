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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
