# New ports collection makefile for:	HTML-Mason
# Date created:				31 May 2000
# Whom:					Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	HTML-Mason
PORTVERSION=	1.50
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dsh@vlink.ru
COMMENT=	High-performance, dynamic web site authoring system

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Cache-Cache>=1:${PORTSDIR}/devel/p5-Cache-Cache \
		p5-Class-Container>=0.07:${PORTSDIR}/devel/p5-Class-Container \
		p5-Exception-Class>=1.15:${PORTSDIR}/devel/p5-Exception-Class \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Log-Any>=0.08:${PORTSDIR}/devel/p5-Log-Any \
		p5-Params-Validate>=0.70:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-CHI>=0.210:${PORTSDIR}/devel/p5-CHI \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Memory-Cycle>=0:${PORTSDIR}/devel/p5-Test-Memory-Cycle

PERL_CONFIGURE=	yes

MAN3=		HTML::Mason.3 \
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

OPTIONS_DEFINE=	MODPERL

post-patch:
	@${REINPLACE_CMD} -e '/bin\/convert/d' ${WRKSRC}/Makefile.PL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script/mason.pl ${PREFIX}/bin/

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPERL}
RUN_DEPENDS+=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2
USE_APACHE=	20+
.endif

.include <bsd.port.mk>
