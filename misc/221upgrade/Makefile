# New ports collection makefile for:	2.2.1R to 2.2-stable upgrade kit
# Version required:	n/a
# Date created:		18 Apr 1997
# Whom:			asami
#
# $Id$
#

DISTNAME=	221upgrade-1998.12.17
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@Freebsd.ORG

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
BROKEN=		this needs to be built on a 2.2-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.post.mk>
