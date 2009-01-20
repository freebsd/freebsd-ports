# New ports collection makefile for:	Path::Class::URI
# Date created:		20 Jan 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Path-Class-URI
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for serialize Path::Class objects as file:// URI

RUN_DEPENDS=	\
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-URI>0:${PORTSDIR}/net/p5-URI \
	p5-Exporter-Lite>0:${PORTSDIR}/devel/p5-Exporter-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Path::Class::URI.3 \
		Path::Class::Unicode.3

.include <bsd.port.mk>
