# New ports collection makefile for:   p5-Mail-OpenRelay-Simple
# Date created:        2006-07-21
# Whom:                Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Mail-OpenRelay-Simple
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Check if a mail server runs as an open relay

RUN_DEPENDS=	p5-Class-Accessor>=0.25:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Net-Telnet>=3.03:${PORTSDIR}/net/p5-Net-Telnet
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Mail::OpenRelay::Simple.3

.include <bsd.port.mk>
