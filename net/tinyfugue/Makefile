# New ports collection makefile for:	tinyfugue
# Version required:	4.0g3
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.15 1999/01/15 02:41:44 asami Exp $
#

DISTNAME=	tf-40g3
PKGNAME=	tf-4.0g3
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/

MAINTAINER=	jseger@FreeBSD.org

.if defined(PARALLEL_PACKAGE_BUILD)
BROKEN=		tries to cd to directory that do not exist yet
.endif

PLIST_SUB=	DISTNAME=${DISTNAME}

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//}

MAN1=		tf.1

.include <bsd.port.mk>
