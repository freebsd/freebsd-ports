# New ports collection makefile for:	upclient
# Date created:		20 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	upclient
PORTVERSION=	4.2.1.21
CATEGORIES=	misc
MASTER_SITES=	http://uptimes.atomicvoid.net/files/ \
		ftp://ftp.uptimes.net/pub/uptimes/ \
		http://www.uptimes.net/download/

MAINTAINER=	clefevre@poboxes.com

ALL_TARGET=	bsd
BUILD_WRKSRC=	${WRKSRC}/src

post-patch:
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' ${WRKSRC}/scripts/upchk

do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/upclient.sh ${PREFIX}/etc/rc.d/upclient.sh
	@${INSTALL_DATA} -m 600 ${WRKSRC}/upclient.conf ${PREFIX}/etc/upclient.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/upchk ${PREFIX}/sbin/upchk
	@${INSTALL_PROGRAM} -g kmem -m 2555 ${WRKSRC}/src/upclient ${PREFIX}/sbin/upclient

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} 's:/usr/local:${PREFIX}:g'

.include <bsd.port.mk>
