# New ports collection makefile for:	logtool
# Date created:		Dec 30, 2000
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	logtool
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://users.digitex.net/~max/

MAINTAINER=	ijliao@csie.nctu.edu.tw

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
ALL_TARGET=	build

post-patch:
	@${PERL} -pi -e "s|make|${GMAKE}|g" ${WRKSRC}/Makefile
.for file in logtool/Makefile logtail/Makefile
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor
	@${PERL} -pi -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/logtool/config.h

.include <bsd.port.mk>
