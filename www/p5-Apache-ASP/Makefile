# New ports collection makefile for:	p5-Apache-ASP
# Date created:				31 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-ASP
PORTVERSION=	2.61
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	${MODPERL_SUFFIX}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Active Server Pages for Apache

RUN_DEPENDS=	${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/HTML/Clean.pm:${PORTSDIR}/www/p5-HTML-Clean \
		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MLDBM/Sync.pm:${PORTSDIR}/databases/p5-MLDBM-Sync \
		${SITE_PERL}/Tie/Cache.pm:${PORTSDIR}/devel/p5-Tie-Cache \
		${SITE_PERL}/XML/XSLT.pm:${PORTSDIR}/textproc/p5-XML-XSLT \
		${SITE_PERL}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron

.if !defined(WITHOUT_MODPERL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/Apache/Filter.pm:${PORTSDIR}/www/p5-Apache-Filter \
		${SITE_PERL}/Apache/SSI.pm:${PORTSDIR}/www/p5-Apache-SSI
MODPERL_SUFFIX?=+mod_perl
.endif

BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		asp-perl.1
MAN3=		Apache::ASP.3 \
		Apache::ASP::CGI::Table.3 \
		Bundle::Apache::ASP.3 \
		Bundle::Apache::ASP::Extra.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
