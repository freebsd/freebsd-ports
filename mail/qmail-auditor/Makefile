# Created by: Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
# $FreeBSD$

PORTNAME=	qmail-auditor
PORTVERSION=	0.47
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/qmail-auditor/

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Selective e-mail auditing for qmail by means of qmail-queue wrapping

WRKSRC=		${WRKDIR}/${PORTNAME:R}

USES=		qmail:run
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${STAGEDIR}${PREFIX}|g' \
	${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
