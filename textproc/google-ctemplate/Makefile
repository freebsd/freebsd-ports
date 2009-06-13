# ex:ts=8
# Ports collection makefile for:	google-ctemplate
# Date created:			Apr 26, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	google-ctemplate
PORTVERSION=	0.95
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	ctemplate-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A simple but powerful template language for C++

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
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

.include <bsd.port.mk>
