# New ports collection makefile for:	p5-Mail-POP3Client
# Version required:			1.14
# Date created:				October 24th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1996/11/17 07:42:44 obrien Exp $
#

DISTNAME=	POP3Client-1_14
PKGNAME=	p5-Mail-POP3Client-1.14
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.003:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.003:${PORTSDIR}/lang/perl5

MAN3=		Mail::POP3Client.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
