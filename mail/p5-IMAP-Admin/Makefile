# New ports collection makefile for:	p5-IMAP-Admin
# Date created:		Sun Sep 26 09:25:38 EEST 1999
# Whom:	      		Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	IMAP-Admin
PORTVERSION=	1.3.7
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IMAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	martti.kuparinen@iki.fi

PERL_CONFIGURE=	YES

MAN3=		IMAP::Admin.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

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
