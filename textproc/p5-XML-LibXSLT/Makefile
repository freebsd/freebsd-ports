# New ports collection makefile for:	XML::LibXSLT
# Date created:		6 June 2001
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXSLT
PORTVERSION=	1.31
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net

BUILD_DEPENDS=	${PERL_ABASE}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${PERL_ABASE}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.1:${PORTSDIR}/textproc/libxslt

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2'
PERL_ABASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

MAN3=		XML::LibXSLT.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
