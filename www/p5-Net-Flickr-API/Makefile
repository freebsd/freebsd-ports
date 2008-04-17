# New ports collection makefile for:	p5-Net-Flickr-API
# Date created:		2006-07-23
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Flickr-API
PORTVERSION=	1.68
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	Base API class for Net::Flickr::* libraries

RUN_DEPENDS=	${SITE_PERL}/Config/Simple.pm:${PORTSDIR}/devel/p5-Config-Simple \
		${SITE_PERL}/Flickr/API.pm:${PORTSDIR}/www/p5-Flickr-API \
		${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		${SITE_PERL}/${PERL_ARCH}/Readonly.pm:${PORTSDIR}/devel/p5-Readonly
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Flickr::API.3

.include <bsd.port.mk>
