# $FreeBSD$

PORTNAME=	mp_doccer
PORTVERSION=	1.2.2
CATEGORIES=	textproc perl5
MASTER_SITES=	https://triptico.com/download/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	C source code documentation generator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
USE_PERL5=	run

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	mp_doccer

PLIST_FILES=	bin/mp_doccer
PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp_doccer ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
