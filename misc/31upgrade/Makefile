# New ports collection makefile for:	3.1R to 3.1-stable upgrade kit
# Version required:	n/a
# Date created:		8 Mar 1999
# Whom:			asami
#
# $Id$
#

DISTNAME=	31upgrade-1999.03.08
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@Freebsd.ORG

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 310000
IGNORE=		this needs to be built on a 3.1-stable system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.post.mk>
