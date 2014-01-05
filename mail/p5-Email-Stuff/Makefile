# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Email-Stuff
PORTVERSION=	2.102
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chifeng@gmail.com
COMMENT=	More casual approach to creating and sending Email

BUILD_DEPENDS=	p5-prefork>=1.01:${PORTSDIR}/devel/p5-prefork \
		p5-Params-Util>=0.23:${PORTSDIR}/devel/p5-Params-Util \
		p5-File-Type>=0.22:${PORTSDIR}/devel/p5-File-Type \
		p5-Email-MIME>=1.901:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Send>=2.185:${PORTSDIR}/mail/p5-Email-Send
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
