# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PKGNAMEPREFIX=	linux-
PORTVERSION=	5.05-tp1
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/tgz/505/ \
		ftp://ftp.opera.com/pub/opera/linux/505/
DISTNAME=	opera-5.05_tp1-static_qt-libnpp-0.1.1
DISTFILES=	${DISTNAME}.x86${EXTRACT_SUFX}

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

do-configure:
	${SED} 's|%%PREFIX%%|${PREFIX}|; s|%%DATADIR%%|${DATADIR}|;' \
	    <${FILESDIR}/opera.sh >${WRKSRC}/wrapper.sh

do-install:
	(cd ${WRKSRC} && ./install.sh \
	    --exec_prefix=${DATADIR}/bin \
	    --wrapperdir=${PREFIX}/bin \
	    --docdir=${DOCSDIR} \
	    --sharedir=${DATADIR} \
	    --plugindir=${DATADIR}/plugins )

.include <bsd.port.mk>
