# New ports collection makefile for:	Apache-DB
# Date created:	   11 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DB
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Debugging and profiling tools for mod_perl

RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes
USE_APACHE_RUN=	20+

MAN3=		Apache::DB.3 Apache::DProf.3 Apache::perl5db.3 \
		Apache::SmallProf.3

.include <bsd.port.mk>
