# New ports collection makefile for:	XML::Sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Sablotron
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	http://download-1.gingerall.cz/download/sablot/
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A Perl interface to the Sablotron XSLT processor

LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron

USE_ICONV=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS='-L${LOCALBASE}/lib -lexpat -lsablot -liconv' \
		INC='-I${LOCALBASE}/include' \
		EXPATLIBPATH='${LOCALBASE}/lib' \
		EXPATINCPATH='${LOCALBASE}/include' \
		SABLOTLIBPATH='${LOCALBASE}/lib' \
		SABLOTINCPATH='${LOCALBASE}/include'

MAN3=		XML::Sablotron.3 XML::Sablotron::DOM.3 \
		XML::Sablotron::DOM::DOMHandler.3 XML::Sablotron::SAXBuilder.3 \
		XML::Sablotron::Situation::DOMHandlerDispatcher.3

.include <bsd.port.pre.mk>

post-patch:
.if ${PERL_LEVEL} < 500600
	@${PERL} -pi -e 's/^our //; $$_="use vars qw(\$$libs \@extras);\n" if $$.==47' ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
