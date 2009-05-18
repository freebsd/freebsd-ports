# New ports collection makefile for:	uncrustify
# Date created:		03 Jul 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	uncrustify
PORTVERSION=	0.53
CATEGORIES=	textproc
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Highly configurable source code beautifier

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		uncrustify.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
post-install:
	cd ${WRKSRC}/documentation; \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; ; \
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.mk>
