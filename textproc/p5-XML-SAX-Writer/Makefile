# New ports collection makefile for:	XML::SAX::Writer
# Date created:		28 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-Writer
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/SAX/Exception.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/NamespaceSupport.pm:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Filter/BufferText.pm:${PORTSDIR}/textproc/p5-XML-Filter-BufferText
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::SAX::Writer.3 XML::SAX::Writer::XML.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
