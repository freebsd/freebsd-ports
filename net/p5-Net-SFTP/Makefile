# Created by: Trevor Corpropst <tcornpropst@cox.net>
# $FreeBSD$

PORTNAME=	Net-SFTP
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl5 module implementing Secure File Transfer Protocol client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Net-SSH-Perl>=0:net/p5-Net-SSH-Perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
