# New ports collection makefile for:	XML::SAX::Expat
# Date created:		19 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX-Expat
PORTVERSION=	0.35
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/NamespaceSupport.pm:${PORTSDIR}/textproc/p5-XML-NamespaceSupport
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::SAX::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
		@${PERL} -pi -e "s/(?<=XML::SAX::Base          => ')1\.00(?=')/0.25/;" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
