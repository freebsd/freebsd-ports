# ex:ts=8
# New ports collection makefile for:	logtool
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	logtool
PORTVERSION=	1.0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://users.digitex.net/~max/logtool/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	default

ALL_TARGET=	build

post-patch:
.for file in logtool/Makefile logtail/Makefile
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
.for file in logtool/config.h conf/logtool.conf
	@${PERL} -pi -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing logtool docs in ${PREFIX}/share/doc/logtool"
	@${MKDIR} ${PREFIX}/share/doc/logtool && ${CHMOD} a+rx ${PREFIX}/share/doc/logtool
	@${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/logtool
.endif

.include <bsd.port.mk>
