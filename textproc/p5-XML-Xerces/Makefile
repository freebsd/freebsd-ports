# ex:ts=8
# Ports collection makefile for:	p5-XML-Xerces
# Date created:			Jan 19, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	XML-Xerces
PORTVERSION=	2.3.0.4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Perl API to the Apache Xerces XML parser

LIB_DEPENDS=	xerces-c.23:${PORTSDIR}/textproc/xerces-c2

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	XERCES_INCLUDE=${LOCALBASE}/include \
		XERCES_LIB=${LOCALBASE}/lib
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"requires perl 5.6.x or later. Install lang/perl5 and try again"
.endif

post-patch:
	@${PERL} -pi -e "s|-lpthread|${PTHREAD_LIBS}|" ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
