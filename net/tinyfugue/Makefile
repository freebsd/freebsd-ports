# New ports collection makefile for:	tinyfugue
# Version required:	4.0s1
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.16 1999/02/16 03:06:21 jseger Exp $
#

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/ \
		http://ftp.tcp.com/pub/mud/Clients/tinyfugue \
		ftp://ftp.progsoc.uts.edu.au/pub/tinyfugue/ \
		ftp://ftp.minet.uni-jena.de/pub/tf/ \
		ftp://ftp.ci.uminho.pt/pub/mirrors/tinyfugue/

MAINTAINER=	jseger@FreeBSD.org

.if defined(PARALLEL_PACKAGE_BUILD)
BROKEN=		tries to cd to directory that do not exist yet
.endif

PLIST_SUB=	DISTNAME=${DISTNAME}

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//}

MAN1=		tf.1

.include <bsd.port.mk>
