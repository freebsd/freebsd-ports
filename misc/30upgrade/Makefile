# New ports collection makefile for:	3.0R to 3.0-current upgrade kit
# Version required:	n/a
# Date created:		17 Dec 1998
# Whom:			asami
#
# $Id$
#

DISTNAME=	30upgrade-1998.12.17
CATEGORIES=	misc
DISTFILES=	# empty

MAINTAINER=	asami@Freebsd.ORG

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		this needs to be built on a 3.0-current system
.endif
NO_MTREE=	yes
PREFIX=		/
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.post.mk>
