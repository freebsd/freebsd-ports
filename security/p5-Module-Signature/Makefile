# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	Module-Signature
PORTVERSION=	0.79
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Module signature file manipulation

BUILD_DEPENDS=	p5-PAR-Dist>=0:${PORTSDIR}/devel/p5-PAR-Dist
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run

CONFIGURE_ENV=	PERL_MM_USE_DEFAULT="yes"
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFAULT=	GPG2
OPTIONS_MULTI=		GPG
OPTIONS_MULTI_GPG=	GPG1 GPG2

GPG1_DESC=	Use GnuPG version 1
GPG2_DESC=	Use GnuPG version 2

GPG1_BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
GPG1_RUN_DEPENDS=	${GPG1_BUILD_DEPENDS}

GPG2_BUILD_DEPENDS=	gpgv2:${PORTSDIR}/security/gnupg
GPG2_RUN_DEPENDS=	${GPG2_BUILD_DEPENDS}

.include <bsd.port.mk>
