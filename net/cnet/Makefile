# New ports collection makefile for:    cnet
# Date created:         Feb 8th, 1988
# Whom:                 jkh
#
# $FreeBSD$
#

PORTNAME=	cnet
PORTVERSION=	1.5.p2
CATEGORIES=	net tk82
MASTER_SITES=	http://www.cs.uwa.edu.au/cnet/
DISTNAME=	cnet-1.5-2

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty
MAN1=		cnet.1

post-extract:
	${CP} ${FILESDIR}/Makefile.freebsd ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/freebsd
	${CP} ${FILESDIR}/compile.c ${WRKSRC}/src/freebsd

post-patch:
	@${PERL} -pi.in \
		-e "s|%%CC%%|${CC}|g;" \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
			${WRKSRC}/src/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/cnet ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/cnet.h ${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/DOC/cnet.man ${PREFIX}/man/man1/cnet.1
	@${MKDIR} ${PREFIX}/libdata/cnet
	${INSTALL_DATA} ${WRKSRC}/src/tcltk/cnet.tcl ${PREFIX}/libdata/cnet
	${INSTALL_DATA} ${WRKSRC}/src/tcltk/cnet_icon.bmp ${PREFIX}/libdata/cnet
	@${MKDIR} ${PREFIX}/share/examples/cnet
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES/* ${PREFIX}/share/examples/cnet

.include <bsd.port.mk>
