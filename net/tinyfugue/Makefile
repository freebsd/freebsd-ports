# New ports collection makefile for:	tinyfugue
# Version required:	4.0b2
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.10 1998/07/26 03:15:45 jseger Exp $
#

DISTNAME=	tf-40b2
PKGNAME=	tf-4.0b2
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	jseger@FreeBSD.org

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//}

MAN1=		tf.1

.include <bsd.port.mk>
