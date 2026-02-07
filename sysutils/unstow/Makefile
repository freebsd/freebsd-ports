PORTNAME=	unstow
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.github.com/ \
		ftp://ftp.iDaemons.org/pub/distfiles/
DISTNAME=	knu-stow-utils-885c88a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Script to unstow packages much faster than stow -D
WWW=		https://github.com/knu/stow-utils

NO_BUILD=	yes

PLIST_FILES=	bin/unstow share/man/man1/unstow.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/unstow.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
