# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	WWW-Link
PORTVERSION=	0.036
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Maintain information about the state of links

DEPRECATED=	Depends on expired www/p5-CGI-modules
EXPIRATION_DATE=2014-04-10

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Stream>=0:${PORTSDIR}/www/p5-HTML-Stream \
		p5-CGI-modules>=0:${PORTSDIR}/www/p5-CGI-modules \
		p5-Net-Telnet>=0:${PORTSDIR}/net/p5-Net-Telnet \
		p5-MLDBM>=0:${PORTSDIR}/databases/p5-MLDBM \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
