# New ports collection makefile for:	textproc/p5-XML-DT
# Date created:				01 January 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	XML-DT
PORTVERSION=	0.19
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::DT.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/XML/DT/examples
	@${MKDIR} ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/XML/DT/examples/XPath
	@${INSTALL_DATA} ${WRKSRC}/examples/XPath/* ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/XML/DT/examples/XPath
	@${INSTALL_DATA} `ls -d ${WRKSRC}/examples/* | ${GREP} -v XPath` ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/XML/DT/examples

.include <bsd.port.mk>
