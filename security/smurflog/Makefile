# Ports collection Makefile for:	smurflog
# Date created:				7/06/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	smurflog
PORTVERSION=	2.1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.bitchx.org/pub/misc/                          \
		ftp://ftp.plur.net/pub/software/bitchx/files/           \
		http://www.nectar.com/distfiles/

MAINTAINER=	nectar@FreeBSD.org

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.smurflog
	${INSTALL_PROGRAM} ${WRKSRC}/smurflog ${PREFIX}/sbin/smurflog

.include <bsd.port.mk>
