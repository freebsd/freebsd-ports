# New ports collection makefile for:	2.2.5R to 2.2-stable upgrade kit
# Version required:	n/a
# Date created:		30 Nov 1997
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1998/12/17 23:42:19 asami Exp $
#

DISTNAME=	225upgrade-1998.03.08
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@Freebsd.ORG

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
IGNORE=		this needs to be built on a 2.2-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.post.mk>
