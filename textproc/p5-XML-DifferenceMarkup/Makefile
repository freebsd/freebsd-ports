# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-DifferenceMarkup
PORTVERSION=	1.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module implements an XML diff producing XML output

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libdiffmark.so:textproc/diffmark

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} '/^\$$CC/s|g++|${CXX}|; s|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.PL

# Don't pass any argument to Makefile.PL, it messes up lib detection.
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_ARGS} \
		${PERL5} ${CONFIGURE_CMD}

.include <bsd.port.mk>
