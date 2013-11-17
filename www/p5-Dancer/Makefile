# $FreeBSD$

PORTNAME=	Dancer
PORTVERSION=	1.3119
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YANICK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for minimal-effort oriented web application framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-HTTP-Body>=1.07:${PORTSDIR}/www/p5-HTTP-Body \
	p5-HTTP-Server-Simple-PSGI>=0.11:${PORTSDIR}/www/p5-HTTP-Server-Simple-PSGI \
	p5-MIME-Types>0:${PORTSDIR}/mail/p5-MIME-Types \
	p5-URI>=1.59:${PORTSDIR}/net/p5-URI \
	p5-Try-Tiny>=0.09:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP \
	p5-JSON>0:${PORTSDIR}/converters/p5-JSON \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
	p5-HTTP-Parser-XS>0:${PORTSDIR}/www/p5-HTTP-Parser-XS \
	p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output \
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-Clone>0:${PORTSDIR}/devel/p5-Clone
# XXX: test wants p5-Dancer-Session-Cookie, but this causes cyclic dependency.
#	p5-Dancer-Session-Cookie>0:${PORTSDIR}/www/p5-Dancer-Session-Cookie

OPTIONS_DEFINE=	YAML
OPTIONS_DEFAULT=	YAML

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MYAML}
RUN_DEPENDS+=	p5-YAML>=0.71:${PORTSDIR}/textproc/p5-YAML
.endif

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
