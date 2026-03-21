PORTNAME=	comparator
DISTVERSION=	2.14
CATEGORIES=	textproc devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Find common sections in source trees

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
TEST_DEPENDS=	gmake:devel/gmake

USES=		python shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	esr

MAKE_ARGS=	VERSION=${DISTVERSION}
TEST_TARGET=	check
DO_MAKE_TEST=	${SETENVI} ${WRK_ENV} ${TEST_ENV} ${GMAKE} ${MAKE_FLAGS} \
		    ${MAKEFILE} ${TEST_ARGS:N${DESTDIRNAME}=*}
SHEBANG_FILES=	hashgen.py filterator

.include <bsd.port.mk>
