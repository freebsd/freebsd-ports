# New ports collection makefile for:	git
# Version required:	4.3.16
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.8 1996/11/21 11:54:39 asami Exp $
#

DISTNAME=	git-4.3.16
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	YES
MAN1=		git.1 gitaction.1 gitkeys.1 gitmount.1 \
		gitps.1 gitrgrep.1 gitview.1

pre-install:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; patch --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

.include <bsd.port.mk>
