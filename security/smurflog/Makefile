# Ports collection Makefile for:	smurflog
# Version required:			1.0
# Date created:				7/06/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	smurflog-2.1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.uni-klu.ac.at/.disk2/mirrors/internet/bitchx/files/ \
		ftp://ftp.bitchx.org/pub/misc/                          \
		ftp://ftp.plur.net/pub/software/bitchx/files/           \
		http://www.nectar.cc/distfiles/

MAINTAINER=	nectar@FreeBSD.org

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.smurflog
	${INSTALL_PROGRAM} ${WRKSRC}/smurflog ${PREFIX}/sbin/smurflog

.include <bsd.port.mk>
