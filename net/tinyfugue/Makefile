# New ports collection makefile for:	tinyfugue
# Version required:	4.0a11
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.9 1998/04/26 13:15:03 jseger Exp $
#

DISTNAME=	tf-40a11
PKGNAME=	tf-4.0a11
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/

MAINTAINER=	jseger@FreeBSD.org

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//}
#ALL_TARGET=	${MAKE_ARGS} all
#INSTALL_TARGET=	${MAKE_ARGS} install

post-install:
	${LN} -s ${PREFIX}/bin/${DISTNAME} ${PREFIX}/bin/tf

#MAKE_ARGS=	TFVER=${DISTNAME:S/^tf-//}

.include <bsd.port.mk>
