# New ports collection makefile for:	git
# Version required:	4.3.11
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.6 1996/11/17 09:05:46 obrien Exp $
#

DISTNAME=	git-4.3.11
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}

GNU_CONFIGURE=	YES
MAN1=		git.1 gitmount.1 gitcmp.1 gitkeys.1 gitredir.1 gitrgrep.1 \
		gitps.1 gitview.1

pre-install:
	${CP} ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; patch --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

.include <bsd.port.mk>
