# New ports collection makefile for: maildirsync
# Date created:		09 Oct 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	maildirsync
PORTVERSION=	0.3
CATEGORIES=	mail perl5
MASTER_SITES=	http://hacks.dlux.hu/maildirsync/

MAINTAINER=	sergei@kolobov.com
COMMENT=	Online synchronizer for Maildir-format mailboxes

BUILD_DEPENDS=	${LOCALBASE}/bin/perl5.8.0:${PORTSDIR}/lang/perl5.8
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL58=		${LOCALBASE}/bin/perl
POD2MAN=	${LOCALBASE}/bin/pod2man

MAN1=		maildirsync.1

do-build:
	${PERL} -pi -e 's!/usr/bin/perl!${PERL58}!' ${WRKSRC}/maildirsync.pl
	${POD2MAN} ${WRKSRC}/maildirsync.pod > ${WRKSRC}/maildirsync.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/maildirsync.pl ${PREFIX}/bin/maildirsync
	${INSTALL_MAN}    ${WRKSRC}/maildirsync.1  ${MANPREFIX}/man/man1

.include <bsd.port.mk>
