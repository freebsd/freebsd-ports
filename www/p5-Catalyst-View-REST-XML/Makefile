# New ports collection makefile for:	Catalyst::View::REST::XML
# Date created:		05 Feb 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-REST-XML
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Catalyst XML View Class

RUN_DEPENDS=	\
	p5-Catalyst-Runtime>=2.99:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::View::REST::XML.3

.include <bsd.port.mk>
