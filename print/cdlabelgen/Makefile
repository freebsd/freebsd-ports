# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	cdlabelgen
PORTVERSION=	4.2.0
CATEGORIES=	print perl5
MASTER_SITES=	http://www.aczoom.com/pub/tools/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Generate postscript for frontcards and traycards for CDs

USES=		perl5 tar:tgz
MAKE_ARGS=	BASE_DIR="${STAGEDIR}${PREFIX}" \
		LIB_DIR="${STAGEDIR}${DATADIR}" \
		INSTALL="${INSTALL_SCRIPT}" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILE="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		MAN_DIR="${STAGEDIR}${PREFIX}/man"

do-build:
	${PERL5} -i.bak -p -e "if (1 .. 1) {s-^#!/usr/bin/perl-#!${PERL}-;}" ${WRKSRC}/cdlabelgen

.include <bsd.port.mk>
