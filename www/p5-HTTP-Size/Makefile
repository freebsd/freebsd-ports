# New ports collection makefile for:	p5-HTTP-Size
# Date created:				19 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Size
PORTVERSION=	1.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get the byte size of an internet resource

BUILD_DEPENDS=	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-HTML-SimpleLinkExtor>0:${PORTSDIR}/www/p5-HTML-SimpleLinkExtor
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	HTTP::Size.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
