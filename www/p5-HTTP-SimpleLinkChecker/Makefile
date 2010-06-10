# New ports collection makefile for:	p5-HTTP-SimpleLinkChecker
# Date created:				19 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-SimpleLinkChecker
PORTVERSION=	1.16
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Check the HTTP response code for a link

BUILD_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww

MAN1=	http_status.1
MAN3=	HTTP::SimpleLinkChecker.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
