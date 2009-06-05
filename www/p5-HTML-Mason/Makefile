# New ports collection makefile for:	HTML-Mason
# Date created:				31 May 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	HTML-Mason
PORTVERSION=	1.42
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	High-performance, dynamic web site authoring system

BUILD_DEPENDS=	p5-Class-Container>=0.7:${PORTSDIR}/devel/p5-Class-Container \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	p5-Cache-Cache>=1:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Class-Container>=0.7:${PORTSDIR}/devel/p5-Class-Container \
		p5-Exception-Class>=1.15:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Params-Validate>=0.07:${PORTSDIR}/devel/p5-Params-Validate \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser

PERL_MODBUILD=	yes

MAN3=		Bundle::HTML::Mason.3 \
		HTML::Mason.3 \
		HTML::Mason::Admin.3 \
		HTML::Mason::ApacheHandler.3 \
		HTML::Mason::CGIHandler.3 \
		HTML::Mason::Cache::BaseCache.3 \
		HTML::Mason::Compiler.3 \
		HTML::Mason::Compiler::ToObject.3 \
		HTML::Mason::Component.3 \
		HTML::Mason::Component::FileBased.3 \
		HTML::Mason::Component::Subcomponent.3 \
		HTML::Mason::ComponentSource.3 \
		HTML::Mason::Devel.3 \
		HTML::Mason::Escapes.3 \
		HTML::Mason::Exceptions.3 \
		HTML::Mason::FakeApache.3 \
		HTML::Mason::Interp.3 \
		HTML::Mason::Lexer.3 \
		HTML::Mason::MethodMaker.3 \
		HTML::Mason::Params.3 \
		HTML::Mason::Parser.3 \
		HTML::Mason::Plugin.3 \
		HTML::Mason::Plugin::Context.3 \
		HTML::Mason::Request.3 \
		HTML::Mason::Resolver.3 \
		HTML::Mason::Resolver::File.3 \
		HTML::Mason::Resolver::Null.3 \
		HTML::Mason::Subclassing.3 \
		HTML::Mason::Tests.3 \
		HTML::Mason::Tools.3 \
		HTML::Mason::Utils.3

OPTIONS=	MOD_PERL "with mod_perl dependency" off

post-build:
	${MV} -f ${WRKSRC}/bin ${WRKSRC}/bin.orig
	${MV} -f ${WRKSRC}/blib/script ${WRKSRC}/blib/script.orig

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script.orig/mason.pl ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if defined(WITH_MOD_PERL)
.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/libapreq.pm:${PORTSDIR}/www/p5-libapreq
.endif
.endif

.include <bsd.port.post.mk>
