# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Net-Amazon-Thumbnail
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to Amazon Alexa Site Thumbnail web service

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Net::Amazon::Thumbnail.3

NO_STAGE=	yes
post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
