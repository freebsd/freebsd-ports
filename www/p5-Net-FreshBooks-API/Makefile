# New ports collection makefile for:	p5-Net-FreshBooks-API
# Date created:		2010-01-03
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-FreshBooks-API
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy OO access to the FreshBooks.com API

RUN_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Net-OAuth-Simple>=0:${PORTSDIR}/net/p5-Net-OAuth-Simple \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Sub-Override>=0:${PORTSDIR}/devel/p5-Sub-Override \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-WWW-Mechanize>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize \
		p5-Test-XML>=0:${PORTSDIR}/devel/p5-Test-XML

PERL_MODBUILD=	yes

MAN3=		Net::FreshBooks::API.3 \
		Net::FreshBooks::API::Base.3 \
		Net::FreshBooks::API::Client.3 \
		Net::FreshBooks::API::Invoice.3 \
		Net::FreshBooks::API::InvoiceLine.3 \
		Net::FreshBooks::API::Iterator.3 \
		Net::FreshBooks::API::Links.3 \
		Net::FreshBooks::API::OAuth.3 \
		Net::FreshBooks::API::Payment.3 \
		Net::FreshBooks::API::Recurring.3

.include <bsd.port.mk>
