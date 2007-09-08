# New ports collection makefile for:	p5-Jabber-SimpleSend
# Date created:		2006-08-19
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Jabber-SimpleSend
PORTVERSION=	0.02
CATEGORIES=	net-im perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Jabber
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Send a Jabber message simply

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Net/Jabber.pm:${PORTSDIR}/net-im/p5-Net-Jabber
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+	# Inherited from net-im/p5-Net-Jabber

MAN3=		Jabber::SimpleSend.3

.include <bsd.port.mk>
