# New ports collection makefile for:	XML::XUpdate::LibXML
# Date created:		15 July 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-XUpdate-LibXML
PORTVERSION=	0.2.3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Simple implementation of XUpdate format based on and XML::LibXML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		xupdate.1
MAN3=		XML::Normalize::LibXML.3 XML::XUpdate::LibXML.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${PERL} -pi -e 's/xupdate/NAME/ if $$.==56' ${WRKSRC}/xupdate
	@${PERL} -pi -e 's/my // if $$.==237' ${WRKSRC}/lib/XML/XUpdate/LibXML.pm

.include <bsd.port.mk>
