# New ports collection makefile for:	snns
# Version required:	4.1
# Date created:		2 Febuary 1997
# Whom:			reg@shale.csir.co.za
#
# $FreeBSD$
#

DISTNAME=	SNNSv4.1
PKGNAME=	snns-4.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/SNNS/

MAINTAINER=	reg@shale.csir.co.za

USE_XLIB=	yes

post-configure:
	@(cd ${WRKSRC} && ./configure < options.FreeBSD)
	@(${SED} -e "s#%prefix%#${PREFIX}#g" < ${FILESDIR}/snns > ${WRKSRC}/snns)

do-build:
	@(cd ${WRKSRC} && ./build all)

do-install:
	${MKDIR} ${PREFIX}/snns/bin ${PREFIX}/snns/examples
	${INSTALL_PROGRAM} ${WRKSRC}/xgui/bin/other/xgui ${PREFIX}/snns/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/bin/other/* ${PREFIX}/snns/bin
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/snns/examples
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/snns
	${INSTALL_DATA} ${WRKSRC}/Readme.license ${PREFIX}/snns
	${INSTALL_DATA} ${WRKSRC}/default.cfg ${PREFIX}/snns
	${INSTALL_DATA} ${WRKSRC}/help.hdoc ${PREFIX}/snns
	${INSTALL_SCRIPT} ${WRKSRC}/snns ${PREFIX}/bin
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
