# ex:ts=8
# New ports collection makefile for:	logtool
# Date created:			Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	logtool
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://users.digitex.net/~max/

MAINTAINER=	ijliao@csie.nctu.edu.tw

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= default

ALL_TARGET=	build

.if defined(NOPORTDOCS)
NODOCS=		"@comment "
.endif

PLIST_SUB=	NOPORTDOCS=${NODOCS}

post-patch:
.for file in logtool/Makefile logtail/Makefile
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/logtool/config.h

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing logtool docs in ${PREFIX}/share/doc/logtool"
	@${MKDIR} ${PREFIX}/share/doc/logtool && ${CHMOD} a+rx ${PREFIX}/share/doc/logtool
	@${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/logtool
.endif

.include <bsd.port.mk>
