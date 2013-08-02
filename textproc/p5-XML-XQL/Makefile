# New ports collection makefile for:	XML::XQL
# Date created:				Sat Nov 23 17:24:19 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XQL
PORTVERSION=	0.68
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for querying XML tree structures with XQL

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp \
		p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::XQL.3 XML::XQL::DOM.3 XML::XQL::Date.3 \
		XML::XQL::Query.3 XML::XQL::Tutorial.3

.include <bsd.port.mk>
