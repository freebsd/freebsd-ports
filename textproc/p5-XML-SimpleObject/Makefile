# New ports collection makefile for:	p5-XML-SimpleObject
# Date created:				14 November 2001
# Whom:	      				steve
#
# $FreeBSD$
#

PORTNAME=	XML-SimpleObject
PORTVERSION=	0.53
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API for accessing the structure of an XML document

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

WRKSRC?=	${WRKDIR}/${PORTNAME}${PORTVERSION}

PERL_CONFIGURE=	YES
CONFIGURE_ARGS+=	DIR='Enhanced'

MAN3=		XML::SimpleObject.3

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		${WRKSRC}/SimpleObject.pm ${WRKSRC}/LibXML/LibXML.pm

.include <bsd.port.mk>
