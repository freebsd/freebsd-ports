# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	linux-opera
PORTVERSION=	5.0
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/tgz/500/
DISTNAME=	opera-${PORTVERSION}-static.i386

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

NO_BUILD=	yes

do-configure:
	${SED} 's|%%PREFIX%%|${PREFIX}|' <${FILESDIR}/opera.sh >${WRKDIR}/opera.sh

do-install:
	(cd ${WRKSRC} && ./install.sh \
	    --exec_prefix=${PREFIX}/bin \
	    --docdir=${PREFIX}/share/doc/opera \
	    --sharedir=${PREFIX}/share/opera )
	${INSTALL_SCRIPT} ${WRKDIR}/opera.sh ${PREFIX}/bin/opera

.include <bsd.port.mk>
