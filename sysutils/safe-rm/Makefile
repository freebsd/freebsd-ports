# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	safe-rm
PORTVERSION=	0.10
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/safe-rm/trunk/0.10/+download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrapper around the rm command to prevent accidental deletions

LICENSE=	GPLv3

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	safe-rm
NO_BUILD=	yes

DOCS=		COPYING Changes README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/safe-rm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
