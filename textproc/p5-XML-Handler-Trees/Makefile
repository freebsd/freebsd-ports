# New ports collection makefile for:	XML::Handler::Trees
# Date created:		22 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Handler-Trees
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	dos2unix:${PORTSDIR}/converters/unix2dos

PERL_CONFIGURE=	yes

MAN3=		XML::Handler::Trees.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-extract:
	@${FIND} ${WRKSRC} -type f -name "*.p[lm]" | ${XARGS} ${CHMOD} +w
	@${FIND} ${WRKSRC} -type f -name "*.p[lm]" | ${XARGS} dos2unix -p

.include <bsd.port.mk>
