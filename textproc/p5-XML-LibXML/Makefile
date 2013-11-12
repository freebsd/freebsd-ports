# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-LibXML
PORTVERSION=	2.0106
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Gnome libxml2 library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-NamespaceSupport>=1.07:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX>=0.11:${PORTSDIR}/textproc/p5-XML-SAX
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-LeakTrace>=0:${PORTSDIR}/devel/p5-Test-LeakTrace \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	XMLPREFIX=${LOCALBASE}

PKGDEINSTALL=	${PKGINSTALL}

CONFLICTS=	p5-XML-LibXML-XPathContext-[0-9]* p5-XML-LibXML-Common-[0-9]*

.include <bsd.port.mk>
