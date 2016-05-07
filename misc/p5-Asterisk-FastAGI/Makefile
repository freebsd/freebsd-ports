# Created by: Maksym Sobolyev <sobomax@pbxpress.it>
# $FreeBSD$

PORTNAME=	Asterisk-FastAGI
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Perl module for FastAGI handling

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Install>=0:devel/p5-Module-Install \
		p5-Asterisk>=0:misc/p5-Asterisk \
		p5-Net-Server>=0:net/p5-Net-Server \
		p5-File-Remove>=0:devel/p5-File-Remove
RUN_DEPENDS=	p5-Asterisk>=0:misc/p5-Asterisk \
		p5-Net-Server>=0:net/p5-Net-Server

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
