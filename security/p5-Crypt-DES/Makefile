# New ports collection makefile for:	p5-Crypt-DES
# Version required:			1.0
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.5 1997/04/20 13:52:52 wosch Exp $
#

DISTNAME=	Crypt-DES-1.0
PKGNAME=	p5-Crypt-DES-1.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	perl5.004:${PORTSDIR}/lang/perl5
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MAN3=		Crypt::DES.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
