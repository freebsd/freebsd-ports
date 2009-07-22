# New ports collection makefile for: p5-WDDX
# Date created: 		18 September 2001
# Whom: 			Eric A. Griff <eric@talesfromthereal.com>
#
# $FreeBSD$
#

PORTNAME=	WDDX
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/P/PE/PETDANCE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to parse WDDX Packets

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	yes

MAN3=		WDDX.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${DOCSDIR}
.endif

.include <bsd.port.mk>
