# New ports collection makefile for:	git
# Version required:	4.3.19
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	git-4.3.19
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	git

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	YES
MAN1=		git.1 gitaction.1 gitkeys.1 gitmount.1 \
		gitrgrep.1 gitunpack.1

pre-patch:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25

.include <bsd.port.mk>
