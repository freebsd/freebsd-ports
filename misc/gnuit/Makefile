# New ports collection makefile for:	git
# Version required:	4.3.6
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.1.1.1 1995/07/15 23:26:38 torstenb Exp $
#

DISTNAME=	git-4.3.6
CATEGORIES=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

GNU_CONFIGURE=	YES

post-install:
	cp ${PREFIX}/lib/git/term/.gitrc.ansi \
		${PREFIX}/lib/git/term/.gitrc.cons25
	(cd ${PREFIX}/lib/git/term ; patch --quiet -p0 \
		<${FILESDIR}/gitrc.cons25.patch ; rm .gitrc.cons25.orig)
	@gzip -9nf ${PREFIX}/man/man1/git.1 ${PREFIX}/man/man1/gitmatch.1 \
		${PREFIX}/man/man1/gitaction.1 ${PREFIX}/man/man1/gitmount.1 \
		${PREFIX}/man/man1/gitcmp.1 ${PREFIX}/man/man1/gitkeys.1 \
		${PREFIX}/man/man1/gitredir.1 ${PREFIX}/man/man1/gitrgrep.1 \
		${PREFIX}/man/man1/gitps.1 ${PREFIX}/man/man1/gitview.1

.include <bsd.port.mk>
