# New ports collection makefile for:   slrn
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	slrn
PORTVERSION=	0.9.6.3
CATEGORIES=	news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slrn/ \
		ftp://ftp.fu-berlin.de/pub/unix/news/slrn/ \
		ftp://ftp.ntua.gr/pub/lang/slang/ \
		ftp://ftp.plig.org/pub/slrn/


MAINTAINER=	xaa+ports@madison-gurkha.com

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all slrnpull
MAN1=		slrn.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${MACHINE_ARCH}objs/slrn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/${MACHINE_ARCH}objs/slrnpull ${PREFIX}/bin
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
