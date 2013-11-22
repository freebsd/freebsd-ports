# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Email-Stuffer
PORTVERSION=	0.008
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A more casual approach to creating and sending Email

BUILD_DEPENDS=	p5-Params-Util>=0.23:${PORTSDIR}/devel/p5-Params-Util \
		p5-File-Type>=0.22:${PORTSDIR}/devel/p5-File-Type \
		p5-Email-MIME>=1.901:${PORTSDIR}/mail/p5-Email-MIME \
		p5-Email-Sender>=0:${PORTSDIR}/mail/p5-Email-Sender
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Email::Stuffer.3

NO_STAGE=	yes

.include <bsd.port.mk>
