# ex:ts=8
# New ports collection makefile for:	domc
# Date created:			Oct 8, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	domc
PORTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	http://auditorymodels.org/domc/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	expat.1:${PORTSDIR}/textproc/expat

CFLAGS+=	-I${LOCALBASE}/include/xml
SHLIB_MAJOR=	0
INSTALLS_SHLIB=	yes
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

post-patch:
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g ; \
		s,%%CFLAGS%%,${CFLAGS},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/dom.h ${PREFIX}/include
	${CAT} ${WRKSRC}/include/stack.h >> ${PREFIX}/include/dom.h
	${INSTALL_DATA} ${WRKSRC}/libdomc.so.0.5.0 ${PREFIX}/lib/libdomc.so.${SHLIB_MAJOR}
	${LN} -sf ${PREFIX}/lib/libdomc.so.${SHLIB_MAJOR} ${PREFIX}/lib/libdomc.so

.include <bsd.port.mk>
