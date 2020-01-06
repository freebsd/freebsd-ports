# Created by: Michael L. Hostbaek <mich@freebsdcluster.org>
# $FreeBSD$

PORTNAME=	clex
PORTVERSION=	4.6.9
CATEGORIES=	misc
MASTER_SITES=	http://www.clex.sk/download/
DISTNAME=	clex-4.6.patch9

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Command line file manager

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		ncurses gmake

PLIST_FILES=	bin/clex bin/cfg-clex bin/kbd-test \
		man/man1/cfg-clex.1.gz \
		man/man1/clex.1.gz \
		man/man1/kbd-test.1.gz

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
