# Created by: snowchyld
# $FreeBSD$

PORTNAME=	Mail-SRS
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chifeng@gmail.com
COMMENT=	Sender Rewriting Scheme

BUILD_DEPENDS=	p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-MLDBM>=0:${PORTSDIR}/databases/p5-MLDBM
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	Mail::SRS.3 \
	Mail::SRS::DB.3 \
	Mail::SRS::Daemon.3 \
	Mail::SRS::Guarded.3 \
	Mail::SRS::Reversible.3 \
	Mail::SRS::Shortcut.3
MAN1=	srs.1 \
	srsd.1

USES=		perl5
USE_PERL5=	configure

NO_STAGE=	yes
.include <bsd.port.mk>
