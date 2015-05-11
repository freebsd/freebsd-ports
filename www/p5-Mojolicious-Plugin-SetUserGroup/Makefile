# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojolicious-Plugin-SetUserGroup
PORTVERSION=	0.002
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DBOOK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mojolicious plugin to set unprivileged credentials

LICENSE=	ART20

BUILD_DEPENDS=	p5-Mojolicious>=6.0:${PORTSDIR}/www/p5-Mojolicious \
		p5-Unix-Groups>=0:${PORTSDIR}/devel/p5-Unix-Groups
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501905
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.33:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.33:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
