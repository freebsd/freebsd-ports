# New ports collection makefile for:	www/p5-POE-Component-Server-SOAP
# Date created:				12 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-SOAP
PORTVERSION=	1.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Publish POE event handlers via SOAP over HTTP

BUILD_DEPENDS=	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/POE/Component/Server/SimpleHTTP.pm:${PORTSDIR}/www/p5-POE-Component-Server-SimpleHTTP \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Server::SOAP.3 \
	POE::Component::Server::SOAP::Response.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use warnings/;' \
		${WRKSRC}/lib/POE/Component/Server/SOAP.pm \
		${WRKSRC}/lib/POE/Component/Server/SOAP/Response.pm
.endif
.include <bsd.port.post.mk>
