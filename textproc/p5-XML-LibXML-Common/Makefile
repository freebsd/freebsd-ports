# New ports collection makefile for:	XML::LibXML::Common
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-Common
PORTVERSION=	0.13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

# Feel free to update this port when the CPAN module is updated
MAINTAINER=	knu@FreeBSD.org
COMMENT=	Routines and Constants common for XML::LibXML and XML::GDOME

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2'

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		XML::LibXML::Common.3

.include <bsd.port.mk>
