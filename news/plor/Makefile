# New ports collection makefile for:	plor
# Version Required:	0.1 alpha
# Date Created:		30 Dec 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id$
#

DISTNAME=	plor
PKGNAME=	plor-0.1
CATEGORIES=	news
# supposedly the primary site is sunsite, but the version there is
# out-of-date, so... sunsite.unc.edu /pub/Linux/system/BBS/mail/ if you 
# want to try again...
MASTER_SITES=   ftp://ftp.dei.unipd.it/pub/pluto/developers/

MAINTAINER=	ac199@freenet.hamilton.on.ca

EXTRACT_SUFX=	.tgz
MAN1=		plor.1

DOCFILES=	BUGS HISTORY PER_ZENO TODO plor-1.html plor-2.html \
		plor.html plor.txt

do-install:
.if !defined{NOPORTDOCS}
	@${MKDIR} ${PREFIX}/share/doc/plor
	(for f in ${DOCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$f ${PREFIX}/share/doc/plor; \
		done)
	${INSTALL_DATA} ${FILESDIR}/porting.notes ${PREFIX}/share/doc/plor
.endif
	${INSTALL_MAN} ${FILESDIR}/plor.1 ${PREFIX}/man/man1/plor.1
	perl -pi -e '$$a = '\''${PREFIX}/doc/plor/'\''; $$a =~ s/([^\w\/])/\\$$1/g; s/FUNKYTOKENHERE/$$a/' ${PREFIX}/man/man1/plor.1
	${INSTALL_PROGRAM} ${WRKSRC}/plor ${PREFIX}/bin

.include <bsd.port.mk>
