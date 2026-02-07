PORTNAME=	tinyexpr
DISTVERSION=	g20221120
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny expression parser/compiler/evaluation engine for math expressions
WWW=		https://codeplea.com/tinyexpr

LICENSE=	MIT

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	codeplea
GH_TAGNAME=	74804b8

PLIST_FILES=	include/${PORTNAME}.h \
		lib/lib${PORTNAME}.so

do-build:
	@cd ${WRKSRC} && \
		${CC} ${CFLAGS} -fPIC ${LDFLAGS} -Wl,-soname,lib${PORTNAME}.so -shared -lm -o lib${PORTNAME}.so ${PORTNAME}.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
