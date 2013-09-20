# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Template-Plugin-Clickable-Email
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	TT plugin to make email addresses into HTML links

BUILD_DEPENDS=	p5-Email-Find>=0:${PORTSDIR}/mail/p5-Email-Find \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Template::Plugin::Clickable::Email.3

NO_STAGE=	yes
.include <bsd.port.mk>
