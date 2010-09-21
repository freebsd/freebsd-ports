# New ports collection makefile for:	muparser
# Date created:		2006-02-14
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	muparser
PORTVERSION=	1.34
CATEGORIES=	math devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Mathematical expressions parser library written in C++

USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared=no
.if defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-samples=no
.endif
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
.endif
USE_GMAKE=	yes

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
