# New ports collection makefile for:	p5-Maypole
# Date created:				Apr 2 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Maypole
PORTVERSION=	1.3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SI/SIMON/
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	MVC web application framework

BUILD_DEPENDS=	${SITE_PERL}/Class/DBI/Loader.pm:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		${SITE_PERL}/Class/DBI/AbstractSearch.pm:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		${SITE_PERL}/Class/DBI/Pager.pm:${PORTSDIR}/databases/p5-Class-DBI-Pager \
		${SITE_PERL}/Class/DBI/Plugin/RetrieveAll.pm:${PORTSDIR}/databases/p5-Class-DBI-Plugin-RetrieveAll \
		${SITE_PERL}/Class/DBI/AsForm.pm:${PORTSDIR}/databases/p5-Class-DBI-AsForm \
		${SITE_PERL}/Class/DBI/FromCGI.pm:${PORTSDIR}/databases/p5-Class-DBI-FromCGI \
		${SITE_PERL}/Class/DBI/Loader/Relationship.pm:${PORTSDIR}/databases/p5-Class-DBI-Loader-Relationship \
		${SITE_PERL}/CGI/Untaint.pm:${PORTSDIR}/www/p5-CGI-Untaint \
		${SITE_PERL}/UNIVERSAL/moniker.pm:${PORTSDIR}/devel/p5-UNIVERSAL-moniker \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

PERL_CONFIGURE=	yes

MAN3=		Apache::MVC.3 \
		Maypole.3 \
		Maypole::Model::Base.3 \
		Maypole::Model::CDBI.3 \
		Maypole::Workflow.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Perl 5.6 or newer required. Install lang/perl5 or lang/perl5.8 and try again."
.endif

.include <bsd.port.post.mk>
