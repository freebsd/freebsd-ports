# New ports collection makefile for:	git
# Version required:	4.3.11
# Date created:		12 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.2 1995/11/26 10:47:34 asami Exp $
#

DISTNAME=	git-4.3.11
CATEGORIES=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

GNU_CONFIGURE=	YES

pre-install:
	cp ${WRKSRC}/term/.gitrc.ansi \
		${WRKSRC}/term/.gitrc.cons25
	(cd ${WRKSRC}/term ; patch --quiet -p0 <${FILESDIR}/gitrc.cons25.patch )

post_install:
.if !defined(NOMANCOMPRESS)
	@gzip -9nf ${PREFIX}/man/man1/git.1 ${PREFIX}/man/man1/gitmatch.1 \
		${PREFIX}/man/man1/gitaction.1 ${PREFIX}/man/man1/gitmount.1 \
		${PREFIX}/man/man1/gitcmp.1 ${PREFIX}/man/man1/gitkeys.1 \
		${PREFIX}/man/man1/gitredir.1 ${PREFIX}/man/man1/gitrgrep.1 \
		${PREFIX}/man/man1/gitps.1 ${PREFIX}/man/man1/gitview.1
.endif

.include <bsd.port.mk>
