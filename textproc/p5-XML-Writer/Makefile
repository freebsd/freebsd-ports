# New ports collection makefile for:	XML::Writer
# Date created:				24 December 2000
# Whom:					Adam Herzog <adam@herzogdesigns.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Writer
PORTVERSION=	0.4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

MAN3=		XML::Writer.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
