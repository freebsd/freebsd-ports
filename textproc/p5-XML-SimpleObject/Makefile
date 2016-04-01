# Created by: steve
# $FreeBSD$

PORTNAME=	XML-SimpleObject
PORTVERSION=	0.53
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	API for accessing the structure of an XML document

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC?=	${WRKDIR}/${PORTNAME}${PORTVERSION}

USES=		perl5
USE_PERL5=	configure patch
CONFIGURE_ARGS+=	DIR='Enhanced'

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		${WRKSRC}/SimpleObject.pm ${WRKSRC}/LibXML/LibXML.pm

.include <bsd.port.mk>
