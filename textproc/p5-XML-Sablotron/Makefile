# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-Sablotron
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	http://download-1.gingerall.cz/download/sablot/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the Sablotron XSLT processor

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-11-18

LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron

USES=		iconv perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	LIBS='-L${LOCALBASE}/lib -lexpat -lsablot ${ICONV_LIB}' \
		INC='-I${LOCALBASE}/include' \
		EXPATLIBPATH='${LOCALBASE}/lib' \
		EXPATINCPATH='${LOCALBASE}/include' \
		SABLOTLIBPATH='${LOCALBASE}/lib' \
		SABLOTINCPATH='${LOCALBASE}/include'

MAN3=		XML::Sablotron.3 XML::Sablotron::DOM.3 \
		XML::Sablotron::DOM::DOMHandler.3 XML::Sablotron::SAXBuilder.3 \
		XML::Sablotron::Situation::DOMHandlerDispatcher.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} > 501400
BROKEN=	POLLUTE is gone, does not compile, no release since 2005, textproc/p5-XML-SAXDriver-Sablotron&www/p5-HTML-Webmake depend on me
.endif
.include <bsd.port.post.mk>
