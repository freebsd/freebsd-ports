# New ports collection makefile for:	textproc/p5-XML-DT
# Date created:				01 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	XML-DT
PORTVERSION=	0.45
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for down translation of XML to strings

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/DTDParser.pm:${PORTSDIR}/textproc/p5-XML-DTDParser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		mkdtskel.1 mkdtdskel.1
MAN3=		XML::DT.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
