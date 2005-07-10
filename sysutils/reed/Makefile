# New ports collection makefile for:	reed
# Date created:				7 August 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	reed
PORTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.sacredchao.net/~piman/archive/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A text pager with autoscrolling and more

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configures

MAN1=	breed.1 reed.1 wrap.1

post-patch:
	@${PERL} -pi -e 's!/usr/local!${PREFIX}!g' ${WRKSRC}/configures
	@${PERL} -pi -e 's!sys/dir.h!dirent.h!g;s!.*getopt.h.*\n!!' \
		${WRKSRC}/reed.c
	@${PERL} -pi -e 's!getopt.h !!' ${WRKSRC}/cfg.data
	@${PERL} -pi -e 's!-O2!${CFLAGS}!' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's!^#!/usr/bin/perl!#!${PERL}!' \
		${WRKSRC}/fix_bookmarks.pl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fix_bookmarks.pl ${DATADIR}
.for file in ${MAN1}
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
