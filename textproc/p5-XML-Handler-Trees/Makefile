# New ports collection makefile for:	XML::Handler::Trees
# Date created:		22 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Handler-Trees
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PerlSAX handlers for building tree structures

PERL_CONFIGURE=	yes

MAN3=		XML::Handler::Trees.3

post-extract:
	@${CHMOD} +w ${WRKSRC}/Trees.pm && ${PERL} -pi -e 's|\r||' ${WRKSRC}/Trees.pm

.include <bsd.port.mk>
