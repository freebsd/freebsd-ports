# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	rngstreams
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://statmath.wu-wien.ac.at/software/RngStreams/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C implementation of a high-quality uniform random number generator

LICENSE=	GPLv2+ # code says GPLv2+, COPYING is GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_FILES=	include/RngStream.h \
		lib/librngstreams.a \
		lib/librngstreams.so \
		lib/librngstreams.so.0 \
		lib/librngstreams.so.0.0.0
PORTDOCS=	rngstreams.txt
PORTEXAMPLES=	example1.c

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librngstreams.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DD in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${DD} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for EE in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${EE} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
