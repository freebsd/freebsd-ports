# New ports collection makefile for:	p5-IMAP-Admin
# Date created:		Sun Sep 26 09:25:38 EEST 1999
# Whom:	      		Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	IMAP-Admin
PORTVERSION=	1.6.1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IMAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@freebsd.org

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		IMAP::Admin.3

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
