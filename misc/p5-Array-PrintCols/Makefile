# New ports collection makefile for:	p5-Array-PrintCols
# Version required:			1.2
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1996/11/17 09:06:19 obrien Exp $
#

DISTNAME=	Array-PrintCols-1.2
PKGNAME=	p5-Array-PrintCols-1.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Array

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/Array-PrintCols
MAN3=		Array::PrintCols.3p
MANPREFIX=	${PREFIX}/lib/perl5

.include <bsd.port.mk>
