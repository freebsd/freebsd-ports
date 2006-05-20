# New ports collection makefile for:	p5-XML-Xerces
# Date created:		29 March 2006
# Whom:	      		Ken Menzel <kenm@icarz.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Xerces
PORTVERSION=	2.7.0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTNAME=	XML-Xerces-${PORTVERSION}-0

MAINTAINER=	kenm@icarz.com
COMMENT=	The Perl API to the Apache project's Xerces XML parser

LIB_DEPENDS=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2

USE_GMAKE=	YES
PERL_CONFIGURE=	YES
CONFIGURE_ENV+=	XERCES_LIB="${LOCALBASE}/lib" \
		XERCES_INCLUDE="${LOCALBASE}/include" \

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		this port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
