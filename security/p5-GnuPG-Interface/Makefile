# Created by: trevor
# $FreeBSD$

PORTNAME=	GnuPG-Interface
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for interfacing with GnuPG

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	gpg2:security/gnupg \
		p5-MooX-HandlesVia>=0.04:devel/p5-MooX-HandlesVia \
		p5-MooX-late>=0.14:devel/p5-MooX-late \
		p5-Moo>=0.091011:devel/p5-Moo
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
