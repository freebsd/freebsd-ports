# Ports collection makefile for:	p5-Catalyst-Model-XML-Feed
# Date created:			Apr 5, 2007
# Whom:				lbr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-XML-Feed
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use RSS/Atom feeds as a Catalyst Model

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-XML-Feed>=0.11:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Model::XML::Feed.3 \
	Catalyst::Model::XML::Feed::Item.3

.include <bsd.port.mk>
