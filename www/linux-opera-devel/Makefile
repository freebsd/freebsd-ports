# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	linux-opera
PORTVERSION=	4.0b4
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/tgz/
DISTNAME=	opera-4.0-b4-20001211.012-static.i386

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

NO_BUILD=	yes

do-configure:
	${SED} 's|%%PREFIX%%|${PREFIX}|' <${FILESDIR}/opera.sh >${WRKDIR}/opera

do-install:
	${MKDIR} ${PREFIX}/opera-4.0
	(cd ${WRKSRC} && \
	    tar cf - . | tar --unlink -xpf - -C ${PREFIX}/opera-4.0)
	${INSTALL_SCRIPT} ${WRKDIR}/opera ${PREFIX}/bin/opera

.include <bsd.port.mk>
