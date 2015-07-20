# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	WWW-Shorten-NotLong
PORTVERSION=	9.99
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the web site notlong.com

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.27:${PORTSDIR}/net/p5-URI \
		p5-WWW-Shorten>=0:${PORTSDIR}/www/p5-WWW-Shorten
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	notlong.com is now dead
EXPIRATION_DATE=2015-08-31

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
