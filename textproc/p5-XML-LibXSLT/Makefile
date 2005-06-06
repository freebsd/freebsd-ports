# New ports collection makefile for:	XML::LibXSLT
# Date created:		6 June 2001
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXSLT
PORTVERSION=	1.57
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Perl interface to the GNOME XSLT library

BUILD_DEPENDS=	${PERL_ABASE}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${PERL_ABASE}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2'
PERL_ABASE=	${SITE_PERL}/${PERL_ARCH}

MAN3=		XML::LibXSLT.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${FILESDIR}/500503-*
.endif

.include <bsd.port.post.mk>
