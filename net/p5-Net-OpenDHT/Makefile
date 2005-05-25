# New ports collection makefile for:	p5-Net-OpenDHT
# Date created:			21 May 2005
# Whom:				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Net-OpenDHT
PORTVERSION=	0.29
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Access the Open Distributed Hash Table (Open DHT)

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Chained/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::OpenDHT.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Perl 5.6 or greater required.  Please install lang/perl5 or lang/perl5.8
.endif

.include <bsd.port.post.mk>
