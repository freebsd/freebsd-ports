# Created by: Gregory Neil Shapiro <gshapiro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-HCE_SHA
PORTVERSION=	0.70
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl5 interface to one way hash chaining block cipher

BUILD_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Crypt::HCE_SHA.3

.include <bsd.port.mk>
