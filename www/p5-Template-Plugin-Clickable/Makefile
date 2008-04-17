# New ports collection makefile for:	www/p5-Template-Plugin-Clickable
# Date created:				26 January 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Clickable
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	TT plugin to make URLs clickable in HTML

BUILD_DEPENDS=	p5-URI-Find>=0.13:${PORTSDIR}/textproc/p5-URI-Find \
		p5-Template-Toolkit>=2.07:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::Clickable.3

.include <bsd.port.mk>
