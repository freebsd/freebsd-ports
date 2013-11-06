# Created by: Dom Mitchell <dom@happygiraffe.net>
# $FreeBSD$

PORTNAME=	XML-LibXSLT
PORTVERSION=	1.82
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the GNOME XSLT library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-LibXML>=1.70:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		perl5
USE_GNOME=	libxml2 libxslt
USE_PERL5=	configure

.include <bsd.port.mk>
