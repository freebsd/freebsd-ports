# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	linux-opera
PORTVERSION=	5.0b7
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/tgz/
DISTNAME=	opera-5.0-b7-20010320.018-static.i386
WRKSRC=		${WRKDIR}/${DISTNAME:S/018/020/}

MAINTAINER=	des@FreeBSD.org

IS_INTERACTIVE=	YES

RUN_DEPENDS=	${LINUXBASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && ./install.sh \
	    --exec_prefix=${PREFIX}/bin \
	    --docdir=${PREFIX}/share/doc/opera \
	    --sharedir=${PREFIX}/share/opera )

.include <bsd.port.mk>
