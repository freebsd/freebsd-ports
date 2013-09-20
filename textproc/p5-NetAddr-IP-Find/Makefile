# Created by: Alex Kapranoff <kappa@FreeBSD.org.ua>
# $FreeBSD$

PORTNAME=	NetAddr-IP-Find
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Iterates over all IP addresses in a text similar to Email::Find

RUN_DEPENDS=	p5-NetAddr-IP>0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

MAN3=		NetAddr::IP::Find.3

NO_STAGE=	yes
.include <bsd.port.mk>
