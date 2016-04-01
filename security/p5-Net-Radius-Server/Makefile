# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Net-Radius-Server
PORTVERSION=	1.116
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Framework for RADIUS Servers

RUN_DEPENDS=	p5-Authen-PAM>=0:security/p5-Authen-PAM \
		p5-Class-Accessor>=0.27:devel/p5-Class-Accessor \
		p5-IO-Prompt>=0:devel/p5-IO-Prompt \
		p5-Net-Radius>=1.52:net/p5-Net-Radius \
		p5-Net-Server>=0.94:net/p5-Net-Server \
		p5-NetAddr-IP>=4:net-mgmt/p5-NetAddr-IP \
		p5-perl-ldap>=0:net/p5-perl-ldap

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
