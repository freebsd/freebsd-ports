# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	LWPx-ParanoidAgent
PORTVERSION=	1.10
CATEGORIES=	www security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Subclass of LWP::UserAgent that protects you from harm

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0.58:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
