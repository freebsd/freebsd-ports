# New ports collection makefile for:	quotes
# Version required:	1.3.0
# Date created:         9 February 1999
# Whom:                 Dima Sivachenko
#
# $Id: $
#

DISTNAME=	quotes-1.3-0
PKGNAME=	quotes-1.3.0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.iae.nl/pub/users/grimaldo/ \
		http://www.FreeBSD.org/~billf/distfiles/

MAINTAINER=	dima@Chg.RU

WRKSRC=		${WRKDIR}/Quotes-1.3-0

NO_BUILD=	yes
USE_PERL5=	yes

post-patch:

	@ ${MV} ${WRKSRC}/quotes ${WRKSRC}/quotes.pre_sed
	@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' ${WRKSRC}/quotes.pre_sed \
	> ${WRKSRC}/quotes
	@ ${MV} ${WRKSRC}/QuExample.pm ${WRKSRC}/QuExample.pm.pre_sed
	@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' ${WRKSRC}/QuExample.pm.pre_sed \
	> ${WRKSRC}/QuExample.pm

do-install:

	@ ${INSTALL_SCRIPT} ${WRKSRC}/quotes ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/sample.quotesrc ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/quotes
	@ ${INSTALL_DATA} ${WRKSRC}/quotes.txt ${PREFIX}/share/doc/quotes
	@ ${INSTALL_DATA} ${WRKSRC}/QuExample.pm ${PREFIX}/share/doc/quotes
.endif

.include <bsd.port.mk>
