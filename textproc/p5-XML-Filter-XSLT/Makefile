# New ports collection makefile for:	XML::Filter::XSLT
# Date created:		28 Jan 2002
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Filter-XSLT
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Filter::XSLT.3 XML::Filter::XSLT::LibXSLT.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
