# New ports collection makefile for:	Apache-DB
# Date created:	   11 August 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-DB
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Debugging and profiling tools for mod_perl

PERL_CONFIGURE=	yes

MAN3=		Apache::DB.3 Apache::DProf.3 Apache::SmallProf.3 \
		Apache::perl5db.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Devel/DProf.pm:${PORTSDIR}/devel/p5-Devel-DProf
.endif

.include <bsd.port.post.mk>
