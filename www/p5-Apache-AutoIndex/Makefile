# New ports collection makefile for:	Apache-AutoIndex
# Date created:				Sun Dec 31 20:13:11 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AutoIndex
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A perl module that can completely replace mod_dir and mod_autoindex

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Icon.pm:${PORTSDIR}/www/p5-Apache-Icon \
		${SITE_PERL}/${PERL_ARCH}/Apache/Language.pm:${PORTSDIR}/www/p5-Apache-Language \
		${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		Apache::AutoIndex.3

.include <bsd.port.mk>
