# New ports collection makefile for:	mp3cd
# Date created:		2009-06-15
# Whom:			Sylvio Cesar <scjamorim@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	mp3cd
PORTVERSION=	1.026
CATEGORIES=	multimedia
MASTER_SITES=	http://outflux.net/software/pkgs/mp3cd/download/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Perl script that burns MP3 to audio CDs

BUILD_DEPENDS=	${SITE_PERL}/Config/Simple.pm:${PORTSDIR}/devel/p5-Config-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	5.8.0+

MAN1=	mp3cd.1
MANCOMPRESS=	yes

.include <bsd.port.mk>
