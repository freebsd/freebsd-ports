# Created by: ijliao
# $FreeBSD$

PORTNAME=	lambda
PORTVERSION=	0.1.4
CATEGORIES=	math
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lambda calculus interpreter

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/lambda \
		share/lambda/definitions \
		share/lambda/definitions_with_numbers
PLIST_DIRS=	share/lambda

DOCS=		lambda.html lambdamanual.html user_manual_style.css
PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lambda ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/definitions* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
