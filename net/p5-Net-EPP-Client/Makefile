# New ports collection makefile for:	Net-EPP-Client
# Date created:				18 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-EPP-Client
PORTVERSION=	0.05
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Client library for the TCP transport for EPP

BUILD_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/Net/EPP/Frame.pm:${PORTSDIR}/net/p5-Net-EPP-Frame
RUN_DEPENDS+=	${BUILD_DEPENDS}

MAN3=	Net::EPP::Client.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
