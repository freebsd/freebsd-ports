# Ports collection makefile for:	at
# Date created:				Jun 30, 2003
# Whom:					Heiner Strauss <heiner@bilch.com>
#
# $FreeBSD$

PORTNAME=		at
PORTVERSION=		1.0
PORTREVISION=	3
CATEGORIES=		science
MASTER_SITES=		http://www.hlsresearch.com/oalib/Modes/AcousticsToolbox/
DISTNAME=		at_Unix
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		ports@FreeBSD.org
COMMENT=		The Acoustic ToolBox includes four acoustic models

WRKSRC=                 ${WRKDIR}/at
USE_FORTRAN=		yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/Bellhop/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/Kraken/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/KrakenZ/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/Scooter/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/global/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/misc/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" ${WRKSRC}/tslib/Makefile
	@${REINPLACE_CMD} -e "s|%%FC%%|${FC}|g" -e "s|%%F77%%|${F77}|g" -e "s|%%FFLAGS%%|${FFLAGS}|g" -e "s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/bb/Makefile

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
