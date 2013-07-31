# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	Asterisk
PORTVERSION=	1.03
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JAMESGOL
PKGNAMEPREFIX=	p5-
DISTNAME=	asterisk-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asterisk perl library

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/asterisk-perl-${PORTVERSION}

MAN3=		Asterisk::AGI.3 \
		Asterisk::Manager.3 \
		Asterisk::Outgoing.3 \
		Asterisk::Voicemail.3

.include <bsd.port.mk>
