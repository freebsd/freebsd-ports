# New ports collection makefile for:	XML::Sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-Sablotron
PORTVERSION=	0.98
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A Perl interface to the Sablotron XSLT processor

LIB_DEPENDS=	sablot.70:${PORTSDIR}/textproc/sablotron \
		iconv.3:${PORTSDIR}/converters/libiconv

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
