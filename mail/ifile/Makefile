PORTNAME=	ifile
PORTVERSION=	1.3.8
PORTREVISION=	1
CATEGORIES=	mail textproc
MASTER_SITES=	${WWW}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Application of machine learning to e-mail filtering
WWW=		http://qwone.com/~jason/ifile/

LICENSE=	GPLv2+

USES=		gmake
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

PLIST_FILES=	bin/ifile share/man/man1/ifile.1.gz
PORTDOCS=	ChangeLog NOTES README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ifile ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ifile.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
