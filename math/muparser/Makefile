# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	muparser
PORTVERSION=	2.2.3
CATEGORIES=	math devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mathematical expressions parser library written in C++

LICENSE=	MIT

ALL_TARGET=	lib

DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}

EXAMPLES_CONFIGURE_ENABLE=	samples
EXAMPLES_ALL_TARGET=	samples

GNU_CONFIGURE=	yes

# otherwise it fails to build when the EXAMPLES option is ON
MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_LDCONFIG=	yes
USES=	pathfix zip

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,^(CXXFLAGS|LDFLAGS) = ,\1 ?= ,g' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/samples/example1 && \
	${INSTALL_PROGRAM} example1 ${STAGEDIR}${EXAMPLESDIR} && \
	${INSTALL_DATA} example1.cpp ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
