# New ports collection makefile for:	git
# Version required:	4.3.17
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.9 1997/10/07 08:56:30 tg Exp $
#

DISTNAME=	git-4.3.17
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jseger@FreeBSD.ORG

GNU_CONFIGURE=	YES
MAN1=		git.1 gitaction.1 gitkeys.1 gitmount.1 \
		gitps.1 gitrgrep.1 gitview.1

pre-patch:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25

.include <bsd.port.mk>
