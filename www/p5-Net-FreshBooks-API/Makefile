# New ports collection makefile for:	p5-Net-FreshBooks-API
# Date created:		2010-01-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FreshBooks-API
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Easy OO access to the FreshBooks.com API

RUN_DEPENDS=	p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Clone>0:${PORTSDIR}/devel/p5-Clone \
		p5-Crypt-SSLeay>0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-DateTime>0:${PORTSDIR}/devel/p5-DateTime \
		p5-Lingua-EN-Inflect>0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Net::FreshBooks::API.3 \
		Net::FreshBooks::API::Base.3 \
		Net::FreshBooks::API::Iterator.3 \
		Net::FreshBooks::API::Recurring.3

.include <bsd.port.mk>
