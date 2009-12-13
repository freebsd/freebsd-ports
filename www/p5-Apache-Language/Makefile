# New ports collection makefile for:	Apache-Language
# Date created:				Mon Jan  1 05:22:52 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-Language
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl module that provides language-aware object hashes

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/I18N/LangTags.pm:${PORTSDIR}/misc/p5-I18N-LangTags

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		Apache::Language.3 Apache::Language::Constants.3 \
		Apache::Language::DBI.3 Apache::Language::PlainFile.3

.include <bsd.port.mk>
