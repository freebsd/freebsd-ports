# New ports collection makefile for:	XML-STX
# Date created:	   12 October 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-STX
PORTVERSION=	0.43
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A pure Perl STX processor

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/${PERL_ARCH}/Clone.pm:${PORTSDIR}/devel/p5-Clone \
		${SITE_PERL}/XML/NamespaceSupport.pm:${PORTSDIR}/textproc/p5-XML-NamespaceSupport
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::STX.3 XML::STX::Base.3 XML::STX::Buffer.3 \
		XML::STX::Functions.3 XML::STX::Parser.3 XML::STX::Runtime.3 \
		XML::STX::STXPath.3 XML::STX::Stylesheet.3 XML::STX::TrAX.3 \
		XML::STX::Writer.3

post-extract:
	@${MKDIR} ${WRKSRC}/scripts
	@${MV} ${WRKSRC}/stx*.pl ${WRKSRC}/scripts

post-patch:
	@${PERL} -pi -e 's!(?=stx\w+\.pl)!scripts/!g' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing additional documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
