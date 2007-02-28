# New ports collection makefile for:	DJabberd
# Date created:	   28 February 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DJabberd
PORTVERSION=	0.81
CATEGORIES=	net-im perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Scalable, extensible Jabber/XMPP server framework

BUILD_DEPENDS=	${SITE_PERL}/Danga/Socket.pm:${PORTSDIR}/devel/p5-Danga-Socket \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML/SAX.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/Digest/HMAC_SHA1.pm:${PORTSDIR}/security/p5-Digest-HMAC
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DJabberd.3 DJabberd::Component.3 \
		DJabberd::Component::Example.3 DJabberd::Component::External.3 \
		DJabberd::Component::External::Connection.3 \
		DJabberd::Delivery::LocalVHosts.3

.include <bsd.port.mk>
