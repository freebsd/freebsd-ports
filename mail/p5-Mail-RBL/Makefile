# New ports collection makefile for:	p5-Mail-RBL
# Date created:				July 24th 2002
# Whom:	      				Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Mail-RBL
PORTVERSION=	1.00
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Mail::RBL.3

FILES=		Makefile.PL test.pl RBL.pm

pre-patch:
.for i in ${FILES}
	@${PERL} -pi -e 's/\r//' ${WRKSRC}/${i}
.endfor
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/RBL.pm

.include <bsd.port.mk>
