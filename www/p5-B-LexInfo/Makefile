# New ports collection makefile for:	B-LexInfo
# Date Created:				08 Oct 2003
# Whom:					Trevor S. Cornpropst <tcornpropst@cox.net>
#
# $FreeBSD$
#

PORTNAME=	B-LexInfo
PORTVERSION=	0.02
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	B
PKGNAMEPREFIX=	p5-

MAINTAINER=	tcornpropst@cox.net
COMMENT=	Show information about subroutine lexical variables

.if defined(WITH_MODPERL2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
.else
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
.endif
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		B::LexInfo.3 Apache::RegistryLexInfo.3

.include <bsd.port.mk>
