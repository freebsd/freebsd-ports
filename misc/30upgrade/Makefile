# New ports collection makefile for:	3.1R to 3.1-stable upgrade kit
# Version required:	n/a
# Date created:		17 Dec 1998
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1998/12/17 23:42:20 asami Exp $
#

DISTNAME=	30upgrade-1998.03.08
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@Freebsd.ORG

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
IGNORE=		this needs to be built on a 3.x-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.post.mk>
