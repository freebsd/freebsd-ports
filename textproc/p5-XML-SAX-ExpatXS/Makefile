# New ports collection makefile for:	XML-SAX-ExpatXS
# Date created:	   30 March 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-ExpatXS
PORTVERSION=	1.07
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PerlSAX2 XS extension to Expat parser

RUN_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX
LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lexpat" \
		</dev/null

MAN3=		XML::SAX::ExpatXS.3 XML::SAX::ExpatXS::Encoding.3

.include <bsd.port.mk>
