# Ports collection Makefile for:		p5-AxKit-XSP-Param
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-Param
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	adam@migus.org
COMMENT=	A namespace wrapper for accessing HTTP request paramaters

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		AxKit::XSP::Param.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
