# New ports collection makefile for:	tinyfugue
# Version required:	4.0a4
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.6 1997/11/23 17:54:50 jseger Exp $
#

DISTNAME=	tf-40a4
PKGNAME=	tf-4.0a4
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
