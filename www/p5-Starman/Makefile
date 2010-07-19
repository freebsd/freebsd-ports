# New ports collection makefile for:	Starman
# Date created:		29 Mar 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Starman
PORTVERSION=	0.2006
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for high-performance preforking PSGI web server

RUN_DEPENDS=	\
	p5-Data-Dump>0:${PORTSDIR}/devel/p5-Data-Dump \
	p5-HTTP-Parser-XS>0:${PORTSDIR}/www/p5-HTTP-Parser-XS \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Net-Server>=0.91:${PORTSDIR}/net/p5-Net-Server \
	p5-Plack>=0.9931:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	starman.1
MAN3=	Plack::Handler::Starman.3 \
	Starman.3

.include <bsd.port.mk>
