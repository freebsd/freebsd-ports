# New ports collection makefile for:	palmpower
# Date Created:				22 Aug 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	palmpower
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	palm
#
# The original MASTER_SITE has disappeared:
#	http://www.fh-wilhelmshaven.de/~akcaagaa/palmpower/files/
# It can be downloaded via
#	http://mxlab.com/files/palm/devel/
# but that site doesn't allow direct HTTP transfers.
#

MAINTAINER=	roman@xpert.com
COMMENT=	Disassembler and other tools for PalmOS binaries

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		pilotdis.1

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}.${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=	"Please fetch http://mxlab.com/files/palm/devel/palmpower-1.0.2.tar.gz manually and store it in ${DISTDIR}"
.endif

post-build:
	cd ${WRKSRC}/utils; ${CC} ${CFLAGS} -o splitprc splitprc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pila/pila ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pilotdis/pilotdis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/splitprc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pilotdis.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
