PORTNAME=	BSD-Sysctl
PORTVERSION=	0.12.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	glebius@FreeBSD.org
COMMENT=	Fetch sysctl values from BSD-like systems
WWW=		https://metacpan.org/release/BSD-Sysctl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5
USE_PERL5=	configure

USE_GITHUB=	yes
GH_ACCOUNT=	glebius

pre-install:
	${STRIP_CMD} ${WRKSRC}/blib/arch/auto/BSD/Sysctl/Sysctl.so

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 504200
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-Makefile.PL
.endif

.include <bsd.port.post.mk>
