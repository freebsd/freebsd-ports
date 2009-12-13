# Ports collection Makefile for:		p5-AxKit-XSP-Cookie
# Date created:					8 Jan 2002
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	AxKit-XSP-Cookie
PORTVERSION=	1.41
CATEGORIES=	www perl5
MASTER_SITES=	http://www.cpan.org/authors/id/M/MS/MSERGEANT/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	An XSP library for setting and getting HTTP cookies

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/AxKit.pm:${PORTSDIR}/www/p5-AxKit
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		AxKit::XSP::Cookie.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
