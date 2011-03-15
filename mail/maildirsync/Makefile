# New ports collection makefile for: maildirsync
# Date created:		09 Oct 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	maildirsync
PORTVERSION=	1.1
CATEGORIES=	mail perl5
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online synchronizer for Maildir-format mailboxes

USE_PERL5=	yes

MAN1=		maildirsync.1

do-build:
	${PERL} -pi -e 's!/usr/bin/perl!${PERL}!' ${WRKSRC}/maildirsync.pl
	pod2man ${WRKSRC}/maildirsync.pod > ${WRKSRC}/maildirsync.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/maildirsync.pl ${PREFIX}/bin/maildirsync
	${INSTALL_MAN}    ${WRKSRC}/maildirsync.1  ${MANPREFIX}/man/man1
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sample.sh ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/mailbalance
.for d in lib log trashbags
	${RM} -rf ${WRKSRC}/contrib/mailbalance-0.2.0/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/contrib/mailbalance-0.2.0/* ${EXAMPLESDIR}/mailbalance

.include <bsd.port.mk>
