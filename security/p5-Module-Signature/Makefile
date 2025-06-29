PORTNAME=	Module-Signature
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module signature file manipulation
WWW=		https://metacpan.org/release/Module-Signature

LICENSE=	CC0-1.0

TEST_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run

USES=		perl5
USE_PERL5=	configure

CONFIGURE_ENV=	PERL_MM_USE_DEFAULT="yes"
NO_ARCH=	yes

OPTIONS_MULTI=	GPG
OPTIONS_MULTI_GPG=	GPG1 GPG2
OPTIONS_DEFAULT=GPG2
GPG1_DESC=	Use GnuPG version 1
GPG2_DESC=	Use GnuPG version 2

GPG1_BUILD_DEPENDS=	gpg:security/gnupg1
GPG1_RUN_DEPENDS=	gpg:security/gnupg1
GPG2_BUILD_DEPENDS=	gpg2:security/gnupg
GPG2_RUN_DEPENDS=	gpg2:security/gnupg

.include <bsd.port.mk>
