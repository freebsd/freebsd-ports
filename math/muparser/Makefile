# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	muparser
PORTVERSION=	2.2.0
CATEGORIES=	math devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/./_/g}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mathematical expressions parser library written in C++

LICENSE=	MIT

USES=	pathfix gmake zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared=no
.if defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-samples=no
.endif
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

# taken from audio/taglib
post-patch:
	@${REINPLACE_CMD} -E 's,^(CXXFLAGS|LDFLAGS) = ,\1 ?= ,g' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} && \
	cd ${WRKSRC}/docs/html && \
	${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR} && \
	cd ${WRKSRC}/samples && \
	${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
