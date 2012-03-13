# New ports collection makefile for:	p5-PostScript-PPD
# Date created:		2011-10-21
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PostScript-PPD
PORTVERSION=	0.0203
CATEGORIES=	print perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read PostScript Printer Definition files

PERL_CONFIGURE=	yes

MAN3=		PostScript::PPD.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-IO-Compress>=2:${PORTSDIR}/archivers/p5-IO-Compress
RUN_DEPENDS+=	p5-IO-Compress>=2:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
