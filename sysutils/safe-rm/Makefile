# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	safe-rm
PORTVERSION=	0.12
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/safe-rm/trunk/${PORTVERSION}/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper around the rm command to prevent accidental deletions

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	safe-rm
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/safe-rm
PORTDOCS=	Changes README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/safe-rm ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
