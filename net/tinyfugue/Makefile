# New ports collection makefile for:	tinyfugue
# Version required:	3.5b1
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id$
#

DISTNAME=	tf-35b1
PKGNAME=	tf-3.5b1
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://ftp.tcp.com/pub/mud/Clients/tf/ \
		http://dsmuse.binghamton.edu/archives/clients/tinyfugue/

MAINTAINER=	mike@binghamton.edu

MAN1=		tf.1
MAKEFILE=	${WRKSRC}/unix/Makefile
ALL_TARGET=	${MAKE_ARGS} all
INSTALL_TARGET=	${MAKE_ARGS} install

MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include <bsd.port.mk>
