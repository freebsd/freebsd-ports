# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	NNML
PORTVERSION=	1.14
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Minimal NNTP server

DEPRECATED=	Unmaintained interactive port
EXPIRATION_DATE=2014-08-20

USES=		perl5
USE_PERL5=	configure

RESTRICTED=	License unknown

.if defined(BATCH)
CONFIGURE_ARGS+=	< /dev/null
.else
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.mk>
