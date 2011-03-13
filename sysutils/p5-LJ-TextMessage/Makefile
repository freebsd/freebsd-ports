# New ports collection makefile for:	p5-LJ-TextMessage
# Date created:				25 Mar 2001
# Whom:					Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$

PORTNAME=	LJ-TextMessage
PORTVERSION=	1.5.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://livejournal.com/files/code/textmessage/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-1.4.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 interface to send text messages to phones/pagers

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		LJ::TextMessage.3

.include <bsd.port.mk>
