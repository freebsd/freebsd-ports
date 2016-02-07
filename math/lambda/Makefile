# Created by: ijliao
# $FreeBSD$

PORTNAME=	lambda
PORTVERSION=	0.1.4
CATEGORIES=	math
MASTER_SITES=	http://uniquesoftwaredesigns.com/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lambda calculus interpreter

LICENSE=	GPLv2

USES=		perl5 ncurses readline shebangfix
USE_PERL5=	build
SHEBANG_FILES=	docs/trans_xml_for_cat.pl
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/lambda \
		share/lambda/definitions \
		share/lambda/definitions_with_numbers

DOCS=		lambda.html lambdamanual.html user_manual_style.css
PORTDOCS=	*

post-patch:
	${REINPLACE_CMD} -e 's|-ltermcap|-lncurses|' ${WRKSRC}/configure \
		${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lambda ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/definitions* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
