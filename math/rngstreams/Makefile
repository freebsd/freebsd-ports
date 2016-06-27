# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	rngstreams
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://statmath.wu-wien.ac.at/software/RngStreams/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C implementation of a high-quality uniform random number generator

USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared
USE_LDCONFIG=	yes
PLIST_FILES=	lib/librngstreams.a \
		lib/librngstreams.so.0.0.0 \
		lib/librngstreams.so.0 \
		lib/librngstreams.so \
		include/RngStream.h
PORTDOCS=	rngstreams.txt
PORTEXAMPLES=	example1.c

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for DD in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${DD} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for EE in ${PORTEXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${EE} ${STAGEDIR}${EXAMPLESDIR}
.endfor

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
