# New ports collection makefile for:	ggsd
# Date created:				14 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	ggsd
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	http://people.FreeBSD.org/~billf/distfiles/ \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/
DISTNAME=	ggsd
EXTRACT_SUFX=	.tar

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/GGSD
EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty

do-install:

		@ ${INSTALL_PROGRAM} ${WRKSRC}/ggsd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		@ ${MKDIR} ${PREFIX}/share/doc/ggsd
		@ ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ggsd
		@ ${INSTALL_DATA} ${WRKSRC}/example.scr ${PREFIX}/share/doc/ggsd
.endif

.include <bsd.port.mk>
