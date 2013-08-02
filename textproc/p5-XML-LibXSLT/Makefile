# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	XML-LibXSLT
PORTVERSION=	1.80
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the GNOME XSLT library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-LibXML>=1.70:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2" \
		LIBS="-L${LOCALBASE}/lib"

MAN3=		XML::LibXSLT.3

.include <bsd.port.mk>
