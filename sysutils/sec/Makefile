# $FreeBSD$

PORTNAME=	sec
PORTVERSION=	2.7.0
CATEGORIES=	sysutils
MASTER_SITES=	SF/simple-evcorr/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ecu@200ok.org
COMMENT=	Simple event (logs) correlator

LICENSE=	GPLv2

USE_PERL5_RUN=	yes
USE_RC_SUBR=	sec

NO_BUILD=	yes

MAN8=		sec.8
PORTDOCS=	ChangeLog README

PLIST_FILES=	bin/sec
PORTCONTRIB=	convert.pl itostream.c swatch2sec.pl
PLIST_FILES+=	${PORTCONTRIB:S|^|%%DATADIR%%/|}
PLIST_DIRS+=	%%DATADIR%%

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sec.man ${MANPREFIX}/man/man8/sec.8
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/contrib && ${INSTALL_DATA} ${PORTCONTRIB} ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
