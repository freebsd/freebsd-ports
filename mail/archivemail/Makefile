# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archivemail
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Archive or delete mail older than N days

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=		archivemail.1
DOCS=		CHANGELOG FAQ NEWS README TODO
EXAMPLES=	test_archivemail examples/archivemail_all

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archivemail ${PREFIX}/bin/archivemail
	${INSTALL_MAN} ${WRKSRC}/archivemail.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${EXAMPLES} ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
