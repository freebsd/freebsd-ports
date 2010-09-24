# New ports collection makefile for:	p5-Catalyst-Plugin-AutoRestart
# Date created:				2008-11-23
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-AutoRestart
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Restart Catalyst when specified memory threshold reached

RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3	\
		p5-Class-Data-Accessor>=0:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-Text-SimpleTable>=0:${PORTSDIR}/textproc/p5-Text-SimpleTable \
		p5-Proc-ProcessTable>=0:${PORTSDIR}/devel/p5-Proc-ProcessTable

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::AutoRestart.3

.include <bsd.port.mk>
