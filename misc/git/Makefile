# New ports collection makefile for:	git
# Version required:	4.3.17
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.10 1998/05/03 22:03:50 jseger Exp $
#

DISTNAME=	git-4.3.17
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	git

MAINTAINER=	jseger@FreeBSD.ORG

GNU_CONFIGURE=	YES
MAN1=		git.1 gitaction.1 gitkeys.1 gitmount.1 \
		gitps.1 gitrgrep.1 gitview.1

pre-patch:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25

.include <bsd.port.mk>
