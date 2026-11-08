PORTNAME=	tinyexpr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tiny expression parser/compiler/evaluation engine for math expressions
WWW=		https://codeplea.com/tinyexpr \
		https://github.com/codeplea/tinyexpr

LICENSE=	MIT

USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	codeplea

PLIST_FILES=	include/${PORTNAME}.h \
		lib/lib${PORTNAME}.so

do-build:
	@cd ${WRKSRC} && \
		${CC} ${CFLAGS} -fPIC ${LDFLAGS} -Wl,-soname,lib${PORTNAME}.so -shared -lm -o lib${PORTNAME}.so ${PORTNAME}.c

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so ${STAGEDIR}${PREFIX}/lib

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} CC=${CC} smoke

.include <bsd.port.mk>
