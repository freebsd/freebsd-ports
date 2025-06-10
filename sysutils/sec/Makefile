PORTNAME=	sec
DISTVERSION=	2.9.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/simple-evcorr/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ecu@200ok.org
COMMENT=	Simple event (logs) correlator
WWW=		https://simple-evcorr.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
USE_RC_SUBR=	sec

SHEBANG_FILES=	sec

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	PERL=${PERL}

PORTCONTRIB=	convert.pl itostream.c swatch2sec.pl
PLIST_FILES=	bin/sec \
		share/man/man8/sec.8.gz \
		${PORTCONTRIB:S|^|share/sec/|}
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sec.man ${STAGEDIR}${PREFIX}/share/man/man8/sec.8
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTCONTRIB} ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
