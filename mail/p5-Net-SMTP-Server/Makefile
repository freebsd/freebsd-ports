# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	Net-SMTP-Server
PORTVERSION=	1.1
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	SMTP-Server-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Native Perl SMTP Server

BUILD_DEPENDS=	p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS:=	${BUILD_DEPENDS}

MASTER_SITE_BACKUP+=	http://www.macgyver.org/software/perl/

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
