# New ports collection makefile for:	pipsecd
# Date created:			16 Aug 1999
# Whom:				Patrick Bihan-Faou <patrick@mindstep.com>
#
# $FreeBSD$
#

PORTNAME=	pipsecd
PORTVERSION=	19991014
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.enst.fr/~beyssac/pipsec/ \
		http://www.mindstep.com/pipsec/
DISTNAME=	pipsec-19991014

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Simple IPSEC tunnel tool from Pierre Beyssac

USE_OPENSSL=	YES

ALL_TARGET=	pipsecd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipsecd ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/pipsecd.sh ${PREFIX}/etc/rc.d
	${CHMOD} 755 ${PREFIX}/etc/rc.d/pipsecd.sh;
	${MKDIR} ${PREFIX}/etc/ipsec
	${INSTALL_DATA} ${WRKSRC}/pipsecd.conf.sample ${PREFIX}/etc/ipsec
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pipsecd
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/pipsecd
	${INSTALL_MAN} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/pipsecd
	${INSTALL_MAN} ${WRKSRC}/README.port ${PREFIX}/share/doc/pipsecd
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/sbin/pipsecd

.include <bsd.port.mk>
