# New ports collection makefile for:   x11iraf
# Date created:	                         22 August 2004
# Whom:	                                 David Syphers <dsyphers@u.washington.edu>
# $FreeBSD$
#

PORTNAME=	x11iraf
PORTVERSION=	1.3.1
CATEGORIES=	science astro
MASTER_SITES=	ftp://iraf.noao.edu/iraf/x11iraf/
DISTNAME=	x11iraf-v${PORTVERSION}-bin.freebsd

MAINTAINER=	dsyphers@u.washington.edu
COMMENT=	Provides graphical tools to work with IRAF

NO_BUILD=	yes
USE_XLIB=	yes

# this may work on other archs, but I'm making no bets
ONLY_FOR_ARCHS=	i386

BINS=		ism_wcspix.e obmsh resize vximtool xgterm ximtool xtapemon

MAN1=		obmsh.1		\
		resize.1	\
		vximtool.1	\
		xgterm.1	\
		ximtool.1	\
		xtapemon.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-install:
	@${ECHO_MSG} "===>  Installing binaries"
	@${INSTALL_PROGRAM} ${BINS:S|^|${WRKDIR}/bin.freebsd/|} ${PREFIX}/bin/
	@${INSTALL_SCRIPT} ${WRKDIR}/bin.freebsd/ximtool-alt ${PREFIX}/bin/
	@${ECHO_MSG} "===>  Installing manpages"
	@${INSTALL_MAN} ${WRKDIR}/man/* ${PREFIX}/man/man1/
	@${ECHO_MSG} "===>  Installing CDL library"
	@${INSTALL_DATA} ${WRKDIR}/include/* ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKDIR}/lib.freebsd/libcdl.a ${PREFIX}/lib/

.include <bsd.port.post.mk>
