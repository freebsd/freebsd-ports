# Created by: Bob Eager <rde@ml1.org.uk>
# $FreeBSD$

PORTNAME=	ml1
PORTVERSION=	4.12
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.ml1.org.uk/distfiles/ \
		http://www.ancientgeek.org.uk/distfiles/

MAINTAINER=	bob@eager.cx
COMMENT=	Original general purpose macro processor

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
.if ${ARCH} == amd64
		@${REINPLACE_CMD} \
		-e '/^#define	FBSD32/s/1/0/' \
		-e '/^#define	FBSD64/s/0/1/'\
		 ${WRKSRC}/ml1.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ml1 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ml1.1.gz \
		${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
