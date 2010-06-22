# New ports collection makefile for:	p5-WWW-Scripter-Plugin-Ajax
# Date created:				28 Jan 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Scripter-Plugin-Ajax
PORTVERSION=	0.07
CATEGORIES=	www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	WWW::Scripter plugin that provides the XMLHttpRequest object

RUN_DEPENDS=	p5-WWW-Scripter-Plugin-JavaScript>0:${PORTSDIR}/www/p5-WWW-Scripter-Plugin-JavaScript \
		p5-XML-DOM-Lite>0:${PORTSDIR}/textproc/p5-XML-DOM-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		WWW::Scripter::Plugin::Ajax.3

.include <bsd.port.mk>
