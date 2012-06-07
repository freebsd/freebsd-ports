# New ports collection makefile for:	p5-LWPx-ParanoidAgent
# Date created:				Tue Dec 19 17:00:41 CST 2006
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	LWPx-ParanoidAgent
PORTVERSION=	1.07
CATEGORIES=	www security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subclass of LWP::UserAgent that protects you from harm

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		LWPx::ParanoidAgent.3

.include <bsd.port.mk>
