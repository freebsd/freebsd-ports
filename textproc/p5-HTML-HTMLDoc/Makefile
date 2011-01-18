# New ports collection makefile for:   p5-HTML-HTMLDoc
# Date created:                13 January 2010
# Whom:                        Konstantin Menshikov <kostjnspb@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	HTML-HTMLDoc
PORTVERSION=	0.10
CATEGORIES=	textproc perl5
MASTER_SITES=	http://kostjn.spb.ru/freebsd/ \
		CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kostjnspb@yandex.ru
COMMENT=	Perl interface to the htmldoc program

BUILD_DEPENDS=	htmldoc>0:${PORTSDIR}/textproc/htmldoc
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		HTML::HTMLDoc.3 HTML::HTMLDoc::PDF.3

.include <bsd.port.mk>
