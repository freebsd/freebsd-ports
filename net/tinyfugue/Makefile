# New ports collection makefile for:	tinyfugue
# Version required:	4.0g2
# Date created:		4 January 1997
# Whom:			mike@binghamton.edu
#
# $Id: Makefile,v 1.12 1998/12/09 05:03:11 jseger Exp $
#

DISTNAME=	tf-40g2
PKGNAME=	tf-4.0g2
CATEGORIES=	net games
MASTER_SITES=	ftp://tf.tcp.com/pub/tinyfugue/

MAINTAINER=	jseger@FreeBSD.org

PLIST_SUB=	DISTNAME=${DISTNAME}

MAKEFILE=	${WRKSRC}/unix/Makefile
MAKE_ENV=	TFVER=${DISTNAME:S/^tf-//}

MAN1=		tf.1

.include <bsd.port.mk>
