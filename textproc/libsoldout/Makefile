# New ports collection makefile for:	libupskirt
# Date created:		2010-02-10
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libupskirt
DISTVERSION=	1.0-rc2
CATEGORIES=	textproc devel
MASTER_SITES=	http://instinctive.eu/code/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Flexible C library for markdown

MAKEFILE=	BSDmakefile
USE_LDCONFIG=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libupskirt.so.1 ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/lace ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kilt ${PREFIX}/bin
	cd ${PREFIX}/lib && ${LN} -s libupskirt.so.1 libupskirt.so
	${MKDIR} ${PREFIX}/include/upskirt
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/upskirt

.include <bsd.port.post.mk>
