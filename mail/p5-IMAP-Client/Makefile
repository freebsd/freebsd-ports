# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	IMAP-Client
PORTVERSION=	0.13
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Advanced manipulation of IMAP services w/ referral support

RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-URI-imap>=0:${PORTSDIR}/mail/p5-URI-imap

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
