# New ports collection makefile for:	p5-MIME-Lite-HTML
# Date created:				2004-06-23 18:16:13
# Whom:	      				Jean-Baptiste Quenot <jb.quenot@caraldi.com>
#
# $FreeBSD$
#

PORTNAME=	MIME-Lite-HTML
PORTVERSION=	1.21
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MIME
PKGNAMEPREFIX=	p5-

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	Provide routine to transform a HTML page into a MIME mail

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		MIME::Lite::HTML.3

.include <bsd.port.mk>
