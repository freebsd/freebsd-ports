# New ports collection makefile for: maildirsync
# Date created:		09 Oct 2002
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	maildirsync
PORTVERSION=	0.4
CATEGORIES=	mail perl5
MASTER_SITES=	http://hacks.dlux.hu/maildirsync/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Online synchronizer for Maildir-format mailboxes

USE_PERL5=	yes

MAN1=		maildirsync.1
PLIST_FILES=	bin/maildirsync

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=	This port requires Perl 5.6.0 or higher.
.endif

do-build:
	${PERL} -pi -e 's!/usr/bin/perl!${PERL}!' ${WRKSRC}/maildirsync.pl
	pod2man ${WRKSRC}/maildirsync.pod > ${WRKSRC}/maildirsync.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/maildirsync.pl ${PREFIX}/bin/maildirsync
	${INSTALL_MAN}    ${WRKSRC}/maildirsync.1  ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
