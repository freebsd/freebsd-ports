# New ports collection makefile for:	tinyfugue
# Version required:	4.0a3
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.5 1997/10/13 09:14:52 tg Exp $
#

DISTNAME=	tf-40a3
PKGNAME=	tf-4.0a3
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	jseger@FreeBSD.org

MAN1=		tf.1
MAKEFILE=	${WRKSRC}/unix/Makefile
ALL_TARGET=	${MAKE_ARGS} all
INSTALL_TARGET=	${MAKE_ARGS} install

MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include <bsd.port.mk>
