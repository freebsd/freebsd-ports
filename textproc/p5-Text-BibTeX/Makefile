# Created by: David Bremner <bremner@unb.ca>
# $FreeBSD$

PORTNAME=	Text-BibTeX
PORTVERSION=	0.66
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:AMBS/Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate BibTeX files from perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-AutoConf>=0.16:${PORTSDIR}/devel/p5-Config-AutoConf \
		p5-ExtUtils-LibBuilder>=0.02:${PORTSDIR}/devel/p5-ExtUtils-LibBuilder
TEST_DEPENDS=	p5-Capture-Tiny>=0.06:${PORTSDIR}/devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	modbuild
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
