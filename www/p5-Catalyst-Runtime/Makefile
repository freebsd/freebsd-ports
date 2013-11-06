# Created by: lbr
# $FreeBSD$

PORTNAME=	Catalyst-Runtime
PORTVERSION=	5.90050
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JJNAPIORK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The Elegant MVC Web Application Framework (Runtime)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Do not add the following ports to TEST_DEPENDS to avoid cyclic dependencies in tinderbox:
# - devel/p5-Test-WWW-Mechanize-Catalyst
# - www/p5-Catalyst-Engine-PSGI
# - www/p5-CatalystX-LeakChecker
#
# DEPENDS: Devel::InnerPackage was first released with perl v5.8.9 and removed from v5.19.0
BUILD_DEPENDS=	p5-CGI-Simple>=1.109:${PORTSDIR}/www/p5-CGI-Simple \
		p5-CGI-Struct>=0:${PORTSDIR}/www/p5-CGI-Struct \
		p5-Catalyst-DispatchType-Regex>=5.90.021:${PORTSDIR}/www/p5-Catalyst-DispatchType-Regex \
		p5-Class-C3-Adopt-NEXT>=0.07:${PORTSDIR}/devel/p5-Class-C3-Adopt-NEXT \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-Load>=0.12:${PORTSDIR}/devel/p5-Class-Load \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Data-OptList>=0:${PORTSDIR}/devel/p5-Data-OptList \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Body>=1.06:${PORTSDIR}/www/p5-HTTP-Body \
		p5-HTTP-Message>=5.814:${PORTSDIR}/www/p5-HTTP-Message \
		p5-HTTP-Request-AsCGI>=1.0:${PORTSDIR}/www/p5-HTTP-Request-AsCGI \
		p5-Hash-MultiValue>=0:${PORTSDIR}/devel/p5-Hash-MultiValue \
		p5-JSON-MaybeXS>=1:${PORTSDIR}/converters/p5-JSON-MaybeXS \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Module-Pluggable>=4.7:${PORTSDIR}/devel/p5-Module-Pluggable \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Emulate-Class-Accessor-Fast>=0.00903:${PORTSDIR}/devel/p5-MooseX-Emulate-Class-Accessor-Fast \
		p5-MooseX-Getopt>=0.30:${PORTSDIR}/devel/p5-MooseX-Getopt \
		p5-MooseX-MethodAttributes>=0.24:${PORTSDIR}/devel/p5-MooseX-MethodAttributes \
		p5-MooseX-Role-WithOverloading>=0.09:${PORTSDIR}/devel/p5-MooseX-Role-WithOverloading \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-MooseX-Types-LoadableClass>=0.003:${PORTSDIR}/devel/p5-MooseX-Types-LoadableClass \
		p5-Path-Class>=0.09:${PORTSDIR}/devel/p5-Path-Class \
		p5-Plack>=0.9991:${PORTSDIR}/www/p5-Plack \
		p5-Plack-Middleware-ReverseProxy>=0.04:${PORTSDIR}/www/p5-Plack-Middleware-ReverseProxy \
		p5-Plack-Test-ExternalServer>=0:${PORTSDIR}/www/p5-Plack-Test-ExternalServer \
		p5-Safe-Isa>=0:${PORTSDIR}/devel/p5-Safe-Isa \
		p5-Stream-Buffered>=0:${PORTSDIR}/devel/p5-Stream-Buffered \
		p5-String-RewritePrefix>=0.004:${PORTSDIR}/textproc/p5-String-RewritePrefix \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Text-SimpleTable>=0.03:${PORTSDIR}/textproc/p5-Text-SimpleTable \
		p5-Tree-Simple>=1.15:${PORTSDIR}/devel/p5-Tree-Simple \
		p5-Tree-Simple-VisitorFactory>=0:${PORTSDIR}/devel/p5-Tree-Simple-VisitorFactory \
		p5-Try-Tiny>=0.17:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-URI>=1.36:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.837:${PORTSDIR}/www/p5-libwww \
		p5-namespace-autoclean>=0.09:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-namespace-clean>=0.23:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Without-Module>=0:${PORTSDIR}/devel/p5-Test-Without-Module \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501800
BUILD_DEPENDS+=	p5-Encode>=2.49:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS+=	p5-Encode>=2.49:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
