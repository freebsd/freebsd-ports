# ex:ts=8
# New ports collection makefile for:	logtool
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	logtool
PORTVERSION=	1.0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://users.digitex.net/~max/logtool/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=/usr/local --sysconfdir=/usr/local/etc/logtool

ALL_TARGET=	build

MAN1=		logtool.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/logtool.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing logtool docs in ${PREFIX}/share/doc/logtool"
	@${MKDIR} ${PREFIX}/share/doc/logtool && ${CHMOD} a+rx ${PREFIX}/share/doc/logtool
	@${CP} -R ${WRKSRC}/doc/examples ${WRKSRC}/doc/logtool.txt ${PREFIX}/share/doc/logtool
.endif

.include <bsd.port.mk>
