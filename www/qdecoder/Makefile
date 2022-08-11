PORTNAME=	qdecoder
PORTVERSION=	12.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C/C++ language library including CGI support

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pathfix

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wolkykim

OPTIONS_DEFINE=	DEBUG EXAMPLES

DEBUG_CONFIGURE_ENABLE=	debug

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libqdecoder.so

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} 'Makefile *.c *.html' ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
