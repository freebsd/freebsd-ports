# New ports collection makefile for:	p5-WebService-Google-Reader
# Date created:				2010-09-06
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	WebService-Google-Reader
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl interface to Google Reader

BUILD_DEPENDS=	p5-JSON-XS>=2:${PORTSDIR}/converters/p5-JSON-XS \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-Class-Accessor>0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Crypt-SSLeay>0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-JSON>=2:${PORTSDIR}/converters/p5-JSON \
		p5-XML-Atom>0:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML

RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WebService::Google::Reader.3 \
		WebService::Google::Reader::Constants.3 \
		WebService::Google::Reader::Feed.3 \
		WebService::Google::Reader::ListElement.3

.include <bsd.port.mk>
