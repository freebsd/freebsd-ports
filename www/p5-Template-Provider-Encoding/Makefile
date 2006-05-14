# New ports collection makefile for:	p5-Template-Provider-Encoding
# Date created:		2006-02-28
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Provider-Encoding
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Template plugin to specify encoding

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

PERL_CONFIGURE=	yes

MAN3=	Template::Provider::Encoding.3 \
	Template::Stash::ForceUTF8.3 \
	Template::Plugin::encoding.3

.include <bsd.port.mk>
