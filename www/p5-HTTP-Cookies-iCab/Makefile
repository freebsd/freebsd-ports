# New ports collection makefile for:	p5-HTTP-Cookies-iCab
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Cookies-iCab
PORTVERSION=	1.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cookie storage and management for iCab

RUN_DEPENDS=	${SITE_PERL}/HTTP/Cookies.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff

PERL_CONFIGURE=	yes

MAN3=		HTTP::Cookies::iCab.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} == 500700 || ${PERL_LEVEL} == 500701
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
