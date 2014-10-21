# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archivemail
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Archive or delete mail older than N days

USES=		python
NO_BUILD=	yes

DOCS=		CHANGELOG FAQ NEWS README TODO
EXAMPLES=	test_archivemail examples/archivemail_all

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archivemail ${STAGEDIR}${PREFIX}/bin/archivemail
	${INSTALL_MAN} ${WRKSRC}/archivemail.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
