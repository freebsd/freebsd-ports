# Ports collection makefile for:	at
# Date created:				Jun 30, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		at
PORTVERSION=		1.0
CATEGORIES=		science
MASTER_SITES=		http://oalib.saic.com/Modes/AcousticsToolbox/
DISTNAME=		at_Unix
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		heiner@bilch.com
COMMENT=		The Acoustic ToolBox includes four acoustic models

WRKSRC=                 ${WRKDIR}/at

do-build:
	cd ${WRKSRC}; ${MAKE} install

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libexec/at
	${INSTALL_PROGRAM} `${FIND} ${WRKSRC} -name \*.out -print` \
		${PREFIX}/libexec/at
	${MKDIR} ${PREFIX}/share/examples/at
	${CP} -rp ${WRKSRC}/tests/* ${PREFIX}/share/examples/at
	${INSTALL_SCRIPT} ${WRKSRC}/at_init ${PREFIX}/share/examples/at
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
