# New ports collection makefile for:	Pod-DocBook
# Date created:	   29 July 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Pod-DocBook
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/N/NA/NANDU
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Convert Pod data to DocBook SGML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Pod/ParseLink.pm:${PORTSDIR}/textproc/p5-podlators \
		${SITE_PERL}/Text/Wrap.pm:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		pod2docbook.1
MAN3=		Pod::DocBook.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	Perl 5.6.1 or newer required. Install lang/perl5.8 or lang/perl5 and try again.
.endif

.include <bsd.port.post.mk>
