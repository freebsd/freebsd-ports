# New ports collection makefile for:    tintin++
# Date created:         15 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	tintin
PORTVERSION=	1.8.6b
CATEGORIES?=	net games
MASTER_SITES=	http://mail.newclear.net/tintin/download/ \
		http://freebsd.hanirc.org/~jhp/tintin++/ \
		http://www.stud.ntnu.no/~sverreno/tintin/
DISTNAME=	tintin++v1.86b

MAINTAINER?=	jhp@cocoja.holywar.net
COMMENT=	"a client program specialized to help playing muds(devel version)"

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/tintin++/src
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt++ ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/tintin
	${INSTALL_DATA} ${WRKSRC}/support/.tt_help.txt.Z ${PREFIX}/lib/tintin
	${MKDIR} ${PREFIX}/share/doc/tintin
	${INSTALL_DATA} ${WRKSRC}/support/.tintinrc ${PREFIX}/share/doc/tintin/tintinrc
	${INSTALL_DATA} ${WRKSRC}/support/tt.conf ${PREFIX}/share/doc/tintin/chat.conf.example
	cd ${WRKSRC}/.. ; ${INSTALL_DATA} CHANGES FAQ CREDITS README docs/* ${PREFIX}/share/doc/tintin

.include <bsd.port.mk>
