# New ports collection makefile for:	XML::Sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Sablotron
PORTVERSION=	0.80
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://download-2.gingerall.cz/download/sablot/
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

LIB_DEPENDS=	sablot.67:${PORTSDIR}/textproc/sablotron \
		iconv.2:${PORTSDIR}/converters/iconv

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS='-L${LOCALBASE}/lib -lexpat -lsablot -liconv' \
		INC='-I${LOCALBASE}/include' \
		EXPATLIBPATH='${LOCALBASE}/lib' \
		EXPATINCPATH='${LOCALBASE}/include' \
		SABLOTLIBPATH='${LOCALBASE}/lib' \
		SABLOTINCPATH='${LOCALBASE}/include'

post-patch:
		@${PERL} -pi -e 's,%%PREFIX%%,${PREFIX},g' \
			${WRKSRC}/Sablotron/Makefile.PL

MAN3=		XML::Sablotron.3 XML::Sablotron::DOM.3 \
		XML::Sablotron::SAXBuilder.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
