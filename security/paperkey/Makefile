PORTNAME=	paperkey
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.jabberwocky.com/software/paperkey/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Extract just the secret information out of OpenPGP secret keys
WWW=		https://www.jabberwocky.com/software/paperkey/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/paperkey share/man/man1/paperkey.1.gz
PORTDOCS=	NEWS README

OPTIONS_DEFINE=	DOCS

# Setting ALL_TARGET to "all check" is racy and breaks parallel builds
post-build:
	${MAKE} -C ${BUILD_WRKSRC} check

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
