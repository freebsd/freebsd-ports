# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clive
PORTVERSION=	2.3.3
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	pierre@guinoiseau.eu
COMMENT=	Command line video extraction tool for YouTube and others

LICENSE=	GPLv3

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod
BUILD_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-JSON-XS>=2.30:${PORTSDIR}/converters/p5-JSON-XS
RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-JSON-XS>=2.30:${PORTSDIR}/converters/p5-JSON-XS \
		quvi>=0.2.16.1:${PORTSDIR}/multimedia/quvi

# deskutils/ljclive, multimedia/clive1 (same executable/manpage/distfile name)
CONFLICTS=	py*-clive-[0-1]* ljclive-[0-9]*

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/clive \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/clive/.packlist \
		man/man1/clive.1.gz
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/clive

.include <bsd.port.mk>
