# New ports collection makefile for:	p5-Catalyst-Plugin-AutoRestart
# Date created:				2008-11-23
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-AutoRestart
PORTVERSION=	0.94
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Restart Catalyst when specified memory threshold reached

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7007:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-Class-Data-Accessor>=0:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-MRO-Compat>=0.07:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Proc-ProcessTable>=0.41:${PORTSDIR}/devel/p5-Proc-ProcessTable \
		p5-Text-SimpleTable>=0.03:${PORTSDIR}/textproc/p5-Text-SimpleTable

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::AutoRestart.3

.include <bsd.port.mk>
