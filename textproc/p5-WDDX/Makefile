# New ports collection makefile for: p5-WDDX
# Date created: 		18 September 2001
# Whom: 			Eric A. Griff <eric@talesfromthereal.com>
#
# $FreeBSD$
#

PORTNAME=	WDDX
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GU/GUELICH
PKGNAMEPREFIX=	p5-

MAINTAINER=	eric@talesfromthereal.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64  \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	yes
ALL_TARGET=	all test
MAN3=		WDDX.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/WDDX
	${INSTALL_MAN} ${WRKSRC}/Changes ${PREFIX}/share/doc/WDDX
.endif

.include <bsd.port.mk>
