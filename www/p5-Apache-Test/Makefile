# New ports collection makefile for:	Apache-Test
# Date created:	   05 July 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-Test
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Test.pm wrapper with helpers for testing Apache

.if defined(WITH_MODPERL2)
IGNORE=		"This port is already included in mod_perl2"
.else
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
BUILD_DEPENDS=	${RUN_DEPENDS}
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::Test.3 Apache::TestConfig.3 Apache::TestSmoke.3 \
		Apache::TestTrace.3 Apache::TestUtil.3 Bundle::ApacheTest.3

post-patch:
	@${PERL} -pi.bak -e 's/^/#/ if $$.==26;' ${WRKSRC}/Makefile.PL

post-configure:
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
