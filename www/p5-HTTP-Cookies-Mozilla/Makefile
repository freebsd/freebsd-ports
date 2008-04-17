# New ports collection makefile for:	p5-HTTP-Cookies-Mozilla
# Date created:		2006-07-10
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Cookies-Mozilla
PORTVERSION=	1.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cookie storage and management for Mozilla

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Cookies::Mozilla.3

.include <bsd.port.mk>
