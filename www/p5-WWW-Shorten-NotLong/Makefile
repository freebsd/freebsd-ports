# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	WWW-Shorten-NotLong
PORTVERSION=	2.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	A Perl interface to the web site notlong.com

BUILD_DEPENDS=	p5-libwww>=5.75:${PORTSDIR}/www/p5-libwww \
		p5-URI>=1.27:${PORTSDIR}/net/p5-URI \
		p5-WWW-Shorten>=0:${PORTSDIR}/www/p5-WWW-Shorten
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
