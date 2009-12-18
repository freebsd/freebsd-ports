# New ports collection makefile for:	Net-EPP-Proxy
# Date created:				19 Feb 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-EPP-Proxy
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A proxy server for the EPP protocol

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-IO-Multiplex>=0:${PORTSDIR}/devel/p5-IO-Multiplex \
		p5-Net-EPP>=0.03:${PORTSDIR}/net/p5-Net-EPP \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=	Net::EPP::Proxy.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
