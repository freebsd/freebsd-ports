# Created by: Juergen Lock <nox@jelal.hb.north.de>
# $FreeBSD$

PORTNAME=	afio
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE/system/backup

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Archiver and backup program with builtin compression

LICENSE=	ART20 BSD2CLAUSE
LICENSE_COMB=	multi

USES=		tar:tgz shebangfix
SHEBANG_FILES=	script1/backup script2/backup

ALL_TARGET=	${PORTNAME}

SUB_FILES=	pkg-message

PLIST_FILES=	bin/afio man/man1/afio.1.gz
PORTDOCS=	HISTORY README SCRIPTS
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} script? ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/afiodump.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
