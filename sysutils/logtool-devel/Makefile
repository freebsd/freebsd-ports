# ex:ts=8
# New ports collection makefile for:	logtool
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	logtool
PORTVERSION=	1.0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xjack.org/logtool/logtool/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}/etc/logtool

ALL_TARGET=	build

MAN1=		logtool.1

post-patch:
	@${PERL} -pi -e "s,%%CFLAGS%%,${CFLAGS},g" ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/logtool.1 ${PREFIX}/man/man1
	@${CP} ${WRKSRC}/conf/logtool.conf ${PREFIX}/etc/logtool/logtool.conf.dist
	@${CP} ${WRKSRC}/conf/exclude ${PREFIX}/etc/logtool/exclude.dist
	@${CP} ${WRKSRC}/conf/green ${PREFIX}/etc/logtool/green.dist
	@${CP} ${WRKSRC}/conf/include ${PREFIX}/etc/logtool/include.dist
	@${CP} ${WRKSRC}/conf/yellow ${PREFIX}/etc/logtool/yellow.dist
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing logtool docs in ${PREFIX}/share/doc/logtool"
	@${MKDIR} ${PREFIX}/share/doc/logtool && ${CHMOD} a+rx ${PREFIX}/share/doc/logtool
	@${CP} -R ${WRKSRC}/doc/examples ${WRKSRC}/doc/logtool.txt ${PREFIX}/share/doc/logtool
.endif

.include <bsd.port.mk>
