# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	2.3.2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	geekounet@poildetroll.net
COMMENT=	Command line video extraction tool for YouTube and others

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-JSON-XS>=2.30:${PORTSDIR}/converters/p5-JSON-XS
RUN_DEPENDS=	p5-Getopt-ArgvFile>=1.11:${PORTSDIR}/devel/p5-Getopt-ArgvFile \
		p5-JSON-XS>=2.30:${PORTSDIR}/converters/p5-JSON-XS \
		quvi>=0.2.16.1:${PORTSDIR}/multimedia/quvi

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

# deskutils/ljclive, multimedia/clive1 (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-1]* ljclive-[0-9]*

PERL_CONFIGURE=	yes

MAN1=		clive.1
PLIST_FILES=	bin/clive \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/clive/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/clive

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-version>=0.77:${PORTSDIR}/devel/p5-version
RUN_DEPENDS+=	p5-version>=0.77:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
