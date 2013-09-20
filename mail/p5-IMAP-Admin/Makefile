# Created by: Martti Kuparinen <martti.kuparinen@ericsson.com>
# $FreeBSD$

PORTNAME=	IMAP-Admin
PORTVERSION=	1.6.7
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chifeng@gmail.com
COMMENT=	Perl module for basic IMAP server administration

USES=		perl5
USE_PERL5=	configure

MAN3=		IMAP::Admin.3
EXAMPLESDIR=	${PREFIX}/share/examples/${UNIQUENAME}

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	create.pl delete.pl
NO_STAGE=	yes
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} "See ${EXAMPLESDIR} for some examples..."
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
