# New ports collection makefile for:	tinyfugue
# Version required:	3.5b4
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.3 1997/01/30 08:42:19 max Exp $
#

DISTNAME=	tf-35b4
PKGNAME=	tf-3.5b4
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	jseger@scds.com

MAN1=		tf.1
MAKEFILE=	${WRKSRC}/unix/Makefile
ALL_TARGET=	${MAKE_ARGS} all
INSTALL_TARGET=	${MAKE_ARGS} install

MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include <bsd.port.mk>
