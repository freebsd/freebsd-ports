PORTNAME=	comparator
DISTVERSION=	2.13
CATEGORIES=	textproc devel

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Find common sections in source trees

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

USES=		python shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	esr

CFLAGS+=	-DLARGEFILES
MAKE_ARGS=	VERSION=${DISTVERSION}
TEST_TARGET=	check
SHEBANG_FILES=	hashgen.py filterator

.include <bsd.port.mk>
