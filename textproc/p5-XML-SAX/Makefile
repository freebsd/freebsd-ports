# New ports collection makefile for:	XML::SAX
# Date created:		19 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-SAX
PORTVERSION=	0.99
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Simple API for XML

BUILD_DEPENDS=	p5-XML-NamespaceSupport>=0.03:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX-Base>=1.05:${PORTSDIR}/textproc/p5-XML-SAX-Base
RUN_DEPENDS=	p5-XML-NamespaceSupport>=0.03:${PORTSDIR}/textproc/p5-XML-NamespaceSupport \
		p5-XML-SAX-Base>=1.05:${PORTSDIR}/textproc/p5-XML-SAX-Base

PERL_CONFIGURE=	yes

MAN3=		XML::SAX.3 XML::SAX::DocumentLocator.3 XML::SAX::Intro.3 \
		XML::SAX::ParserFactory.3 XML::SAX::PurePerl.3 \
		XML::SAX::PurePerl::Reader.3

OPTIONS_DEFINE=	WRITE_INI_OK

WRITE_INI_OK_DESC=	Alter ParserDetails.ini information

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWRITE_INI_OK}
WRITE_INI_OK=	1
.else
WRITE_INI_OK=	0
.endif

post-patch:
# dirty hack to stop asking for confirmation to alter ParserDetails.ini
	@${REINPLACE_CMD} -e 's/%%WRITE_INI_OK%%/${WRITE_INI_OK}/' \
		${WRKSRC}/Makefile.PL

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
