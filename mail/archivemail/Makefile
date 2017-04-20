# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	archivemail
PORTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Archive or delete mail older than N days

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	archivemail  \
		test_archivemail

DOCS=		CHANGELOG FAQ NEWS README TODO
EXAMPLES=	test_archivemail examples/archivemail_all

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archivemail ${STAGEDIR}${PREFIX}/bin/archivemail
	${INSTALL_MAN} ${WRKSRC}/archivemail.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
