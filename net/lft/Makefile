# New ports collection makefile for:	lft
# Date created:			19 Feb 2003
# Whom:				Marco P. Rodrigues <drkangel@drkangel.org>
#
# $FreeBSD$
#

PORTNAME=	lft
PORTVERSION=	3.1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.iasi.roedu.net/mirrors/openwrt.org/sources/ \
		http://trd.no.distfiles.macports.org/lft/ \
		http://mirror2.openwrt.org/sources/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Layer 4 Traceroute program

GNU_CONFIGURE=	yes
MAN8=		lft.8 whob.8
PLIST_FILES=	sbin/lft bin/whob
PORTDOCS=	CHANGELOG README TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lft ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/whob ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${MAN8PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/whob.8 ${MAN8PREFIX}/man/man8/
.ifndef NOPORTDOCS
	${INSTALL} -d ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
