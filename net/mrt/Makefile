# New ports collection makefile for:	mrt
# Date created:		Sat Jun  6 00:09:52 JST 1998
# Whom:			Jun-ichiro itojun Hagino <itojun@itojun.org>
#
# $FreeBSD$
#

PORTNAME=	mrt
PORTVERSION=	2.2.2a
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.merit.edu/net-research/mrt/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-threaded Routing Toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_AUTOCONF_VER=	213

MAN8=		mrtd.8

EXAMPLES=	programs/bgpsim/bgpsim.conf programs/bgpsim/bgpsim6.conf \
		programs/mrtd/mrtd.conf programs/mrtd/mrtd.pim.conf \
		programs/mrtd/mrtd.ripng.conf programs/mrtd/solaris.ripng.conf

post-install:
	@${MKDIR} ${PREFIX}/share/examples/mrt
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/examples/mrt
.endfor

.include <bsd.port.mk>
