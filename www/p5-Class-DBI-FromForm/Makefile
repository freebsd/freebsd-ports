# New ports collection makefile for:	databases/p5-Class-DBI-FromForm
# Date created:				29 May 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Class-DBI-FromForm
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	Update Class::DBI data using Data::FormValidator

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::DBI::FromForm.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.x or later. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
