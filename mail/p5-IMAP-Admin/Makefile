# New ports collection makefile for:	p5-IMAP-Admin
# Version required:	1.2.1
# Date created:		Sun Sep 26 09:25:38 EEST 1999
# Whom:	      		Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

DISTNAME=	IMAP-Admin-1.2.1
PKGNAME=	p5-IMAP-Admin-1.2.1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IMAP

MAINTAINER=	martti.kuparinen@ericsson.com

USE_PERL5=	YES

MAN3=		IMAP::Admin.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
	@${MKDIR} ${PREFIX}/share/examples/p5-IMAP-Admin
	@${INSTALL_DATA} ${WRKSRC}/examples/create.pl \
		${WRKSRC}/examples/delete.pl \
		${PREFIX}/share/examples/p5-IMAP-Admin
	@${ECHO} ""
	@${ECHO} "*******************************************************************************"
	@${ECHO} "See ${PREFIX}/share/examples/p5-IMAP-Admin for some examples..."
	@${ECHO} "*******************************************************************************"
	@${ECHO} ""

.include <bsd.port.mk>
