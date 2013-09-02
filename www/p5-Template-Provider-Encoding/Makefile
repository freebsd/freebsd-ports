# New ports collection makefile for:	p5-Template-Provider-Encoding
# Date created:		2006-02-28
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Provider-Encoding
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Template plugin to specify encoding

RUN_DEPENDS=	p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Template::Provider::Encoding.3 \
	Template::Stash::ForceUTF8.3 \
	Template::Plugin::encoding.3

.include <bsd.port.mk>
