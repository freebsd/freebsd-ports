# New ports collection makefile for:   slrn
# Version required:    0.9.4.3
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $Id: Makefile,v 1.8 1998/05/13 15:25:05 mph Exp $
#

DISTNAME=	slrn0.9.5.2
PKGNAME=	slrn-0.9.5.2
CATEGORIES=	news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/

MAINTAINER=	xaa@xaa.iae.nl

LIB_DEPENDS=	slang\\.1:${PORTSDIR}/devel/libslang

WRKSRC=		${WRKDIR}/slrn
GNU_CONFIGURE=	yes
ALL_TARGET=	all slrnpull
MAN1=		slrn.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/objs/slrn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/objs/slrnpull ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/slrn
	${INSTALL_DATA} ${WRKSRC}/doc/slrn.rc ${PREFIX}/share/examples/slrn
	@${MKDIR} ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/QUICK_INSTALL ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/README ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/score ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/slrn.rc ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/slrnpull.conf ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_DATA} ${WRKSRC}/slrnpull/slrnpull.sh ${PREFIX}/share/examples/slrn/slrnpull
	${INSTALL_MAN} ${WRKSRC}/doc/slrn.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
