# New ports collection makefile for:   p5-Net-Dict
# Date created:                21 July 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Dict
PORTVERSION=	2.07
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple client API for the DICT protocol

BUILD_DEPENDS=	${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Net::Dict.3

post-patch:
	${PERL} -pi -e '$$_="" if /(&configure|EXE_FILES)/' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
