# ex:ts=8
# Ports collection makefile for:	WWW:Mediawiki::Client
# Date created:			Jan 2, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	WWW-Mediawiki-Client
PORTVERSION=	0.31
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A very simple cvs-like interface for Mediawiki websites

BUILD_DEPENDS=	p5-Test-Differences>0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-VCS-Lite>0:${PORTSDIR}/devel/p5-VCS-Lite \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-URI>=1.31:${PORTSDIR}/net/p5-URI \
		p5-Data-Dumper>0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-Exception-Class>0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-Encode>=1.75:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	mvs.1
MAN3=	WWW::Mediawiki::Client.3 WWW::Mediawiki::Client::Exceptions.3

.include <bsd.port.mk>
