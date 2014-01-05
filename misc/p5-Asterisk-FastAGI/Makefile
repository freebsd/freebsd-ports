# Created by: Maksym Sobolyev <sobomax@pbxpress.it>
# $FreeBSD$

PORTNAME=	Asterisk-FastAGI
PORTVERSION=	0.02
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Perl module for FastAGI handling

BUILD_DEPENDS=	p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-Asterisk>=0:${PORTSDIR}/misc/p5-Asterisk \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-File-Remove>=0:${PORTSDIR}/devel/p5-File-Remove
RUN_DEPENDS=	p5-Asterisk>=0:${PORTSDIR}/misc/p5-Asterisk \
		p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
