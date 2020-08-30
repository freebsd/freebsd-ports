# Created by: Vaida Bogdan
# $FreeBSD$

PORTNAME=	dmitry
PORTVERSION=	1.3a
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/UNIX/misc
DISTNAME=	DMitry-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deepmagic Information Gathering Tool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/dmitry man/man1/dmitry.1.gz
PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
