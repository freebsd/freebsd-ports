# New ports collection makefile for:	tinyfugue
# Version required:	4.0s1
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $FreeBSD$
#

DISTNAME=	tf-40s1
PKGNAME=	tf-4.0s1
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/ \
		ftp://laurel.actlab.utexas.edu/pub/tinyfugue/ \
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
