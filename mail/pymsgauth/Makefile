# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	pymsgauth
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://pyropus.ca/software/pymsgauth/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically process qsecretary confirmation requests

USES=		python shebangfix
SHEBANG_FILES=	pymsgauth-clean pymsgauth-confirm pymsgauth-mail
NO_BUILD=	yes

SUB_FILES=	pkg-message

DOCS=		BUGS CHANGELOG pymsgauth.txt pymsgauth.html
EXAMPLES=	pymsgauthrc-example

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${WRKSRC}/pymsgauth-* \
		${STAGEDIR}${DATADIR}
.for f in clean confirm mail
	${LN} -sf ${DATADIR}/pymsgauth-${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
