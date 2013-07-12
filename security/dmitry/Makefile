# Created by: Vaida Bogdan
# $FreeBSD$

PORTNAME=	dmitry
PORTVERSION=	1.3a
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	UNIX/misc
DISTNAME=	DMitry-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Deepmagic Information Gathering Tool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
PLIST_FILES=	bin/dmitry

MAN1=		dmitry.1

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
