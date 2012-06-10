# New ports collection makefile for:	XML::SAX::Expat
# Date created:		19 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-Expat
PORTVERSION=	0.40
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple API for XML

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-NamespaceSupport>=0:${PORTSDIR}/textproc/p5-XML-NamespaceSupport
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::SAX::Expat.3

post-patch:
		@${PERL} -pi -e "s/(?<=XML::SAX::Base          => ')1\.00(?=')/0.25/;" ${WRKSRC}/Makefile.PL

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${PERL} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${PERL} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
