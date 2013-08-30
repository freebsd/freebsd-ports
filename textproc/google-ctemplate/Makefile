# Created by: ijliao
# $FreeBSD$

PORTNAME=	google-ctemplate
PORTVERSION=	2.2
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	ctemplate
DISTNAME=	ctemplate-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A simple but powerful template language for C++

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		pkgconfig

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^pkgconfigdir.*|pkgconfigdir = $${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e \
		's|$$(prefix)/share/doc/$$(PACKAGE)-$$(VERSION)|${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e \
		'/install-data-am/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

tests: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
