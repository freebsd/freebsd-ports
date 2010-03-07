# New ports collection makefile for:	p5-SGML-Parser-OpenSP
# Date created:				27 August 2007
# Whom:					Naram Qashat <cyberbotx@cyberbotx.com>
#
# $FreeBSD$
#

PORTNAME=	SGML-Parser-OpenSP
PORTVERSION=	0.994
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Parse SGML documents using OpenSP

BUILD_DEPENDS=	onsgmls:${PORTSDIR}/textproc/opensp \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes
PERL_CONFIGURE=	yes
CC=		${CXX}
CONFIGURE_ARGS+="INC=-I${LOCALBASE}/include"

MAN3=		SGML::Parser::OpenSP.3 SGML::Parser::OpenSP::Tools.3

post-patch:
	(cd ${WRKSRC} ; \
	 ${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|g" Makefile.PL )

.include <bsd.port.mk>
