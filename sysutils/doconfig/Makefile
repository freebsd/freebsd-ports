# Ports collection Makefile for:	doconfig
# Date created:				7/27/1998
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		doconfig
PORTVERSION=		1.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.cold.org/pub/brandon/

MAINTAINER=		ports@FreeBSD.org

MAN8=			autokernconf.8 doconfig.8

WRKSRC=			${WRKDIR}/doconfig

do-build:
	@ ${MV} ${WRKSRC}/doconfig ${WRKSRC}/_doconfig
	@ ${SED} 's#%%PREFIX%%#${PREFIX}#g' <${WRKSRC}/_doconfig \
		>${WRKSRC}/doconfig
	@ ${RM} ${WRKSRC}/_doconfig

do-install:
.for f in autokernconf doconfig
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/sbin/${f}
.endfor
.for f in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/man/man8/${f}
.endfor

.include <bsd.port.mk>
