PORTNAME=	mbar
PORTVERSION=	2.0
CATEGORIES=	mail
MASTER_SITES=	https://download.gnu.org.ua/release/mbar/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Flexible mailbox archiver based on GNU mailutils
WWW=		https://puszcza.gnu.org.ua/projects/mbar

LICENSE=	GPLv3+

LIB_DEPENDS=	libmailutils.so:mail/mailutils

USES=		gmake
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/mbar share/man/man1/mbar.1.gz
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
