# New ports collection makefile for:	p5-IMAP-Admin
# Date created:		Sun Sep 26 09:25:38 EEST 1999
# Whom:	      		Martti Kuparinen <martti.kuparinen@ericsson.com>
#
# $FreeBSD$
#

PORTNAME=	IMAP-Admin
PORTVERSION=	1.6.4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IMAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for basic IMAP server administration

PERL_CONFIGURE=	YES

MAN3=		IMAP::Admin.3
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/create.pl \
		${WRKSRC}/examples/delete.pl \
		${EXAMPLESDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} "See ${EXAMPLESDIR} for some examples..."
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
