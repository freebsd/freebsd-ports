# New ports collection makefile for:	XML::Parser
# Date created:		15 Nov 1998
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Parser
PORTVERSION=	2.30
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://wwwx.netheaven.com/~coopercc/xmlparser/
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTFILES=	${PORTNAME}.${PORTVERSION}.tar.gz

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	EXPATLIBPATH=${LOCALBASE}/lib EXPATINCPATH=${LOCALBASE}/include

MAN3=		XML::Parser.3 XML::Parser::Expat.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-configure:
	@${PERL} -i -pe 's/^(CC = ).*/$$1 ${CC}/;' \
		-e 's/^(CCFLAGS = ).*/$$1 ${CFLAGS}/' ${WRKSRC}/Expat/Makefile

.include <bsd.port.mk>
