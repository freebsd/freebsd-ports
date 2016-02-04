# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	reed
PORTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Text pager with autoscrolling and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses perl5 shebangfix
USE_PERL5=	run build patch
SHEBANG_FILES=	wrap breed
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	configures

post-patch:
	@${PERL} -pi -e 's!/usr/local!${PREFIX}!g' ${WRKSRC}/configures
	@${PERL} -pi -e 's!sys/dir.h!dirent.h!g;s!.*getopt.h.*\n!!' \
		${WRKSRC}/reed.c
	@${PERL} -pi -e 's!getopt.h !!' ${WRKSRC}/cfg.data
	@${PERL} -pi -e 's!-O2!${CFLAGS}!' ${WRKSRC}/Makefile.in
	@${PERL} -pi -e 's!^#!/usr/bin/perl!#!${PERL}!' \
		${WRKSRC}/fix_bookmarks.pl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/reed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/breed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/wrap ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/fix_bookmarks.pl ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
