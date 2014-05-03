# Created by: Trevor Corpropst <tcornpropst@cox.net>
# $FreeBSD$

PORTNAME=	Net-SFTP
PORTVERSION=	0.10
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl5 module implementing Secure File Transfer Protocol client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Net-SSH-Perl>=0:${PORTSDIR}/net/p5-Net-SSH-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
