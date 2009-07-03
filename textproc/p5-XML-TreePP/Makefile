# New ports collection makefile for:	p5-XML-TreePP
# Date created:		2006-08-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	XML-TreePP
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Pure Perl implementation for parsing/writing xml files

PERL_CONFIGURE=	yes

MAN3=		XML::TreePP.3

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example/envxml.cgi ${EXAMPLESDIR}

.include <bsd.port.mk>
