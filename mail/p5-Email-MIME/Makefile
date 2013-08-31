# $FreeBSD$

PORTNAME=	Email-MIME
PORTVERSION=	1.924
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Easy MIME message parsing

BUILD_DEPENDS=	p5-Email-Simple>=2.102:${PORTSDIR}/mail/p5-Email-Simple \
		p5-Email-MessageID>=0:${PORTSDIR}/mail/p5-Email-MessageID \
		p5-Email-MIME-Encodings>=1.313:${PORTSDIR}/mail/p5-Email-MIME-Encodings \
		p5-Email-MIME-ContentType>=1.01.6:${PORTSDIR}/mail/p5-Email-MIME-ContentType \
		p5-MIME-Types>=1.13:${PORTSDIR}/mail/p5-MIME-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Email::MIME.3 \
		Email::MIME::Creator.3 \
		Email::MIME::Encode.3 \
		Email::MIME::Header.3 \
		Email::MIME::Modifier.3

.include <bsd.port.mk>
