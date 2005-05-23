# New ports collection makefile for:	XML::NamespaceSupport
# Date created:		19 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-NamespaceSupport
PORTVERSION=	1.09
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A simple generic namespace support class

PERL_CONFIGURE=	yes

MAN3=		XML::NamespaceSupport.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500600
	${PERL} -pi -e '$$_="" if /warnings/' ${WRKSRC}/NamespaceSupport.pm
.endif

.include <bsd.port.post.mk>
