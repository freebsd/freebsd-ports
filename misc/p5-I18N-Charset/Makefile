# New ports collection makefile for:    p5-I18N-Charset
# Version required:		1.03
# Date created:			26 December 1999
# Whom:	      			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

DISTNAME=	I18N-Charset-1.03
PKGNAME=	p5-I18N-Charset-1.03
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	I18N

MAINTAINER=	dima@Chg.RU

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		I18N::Charset.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
