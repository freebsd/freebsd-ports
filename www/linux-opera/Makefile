# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PKGNAMEPREFIX=	linux-
PORTVERSION=	6.0-20011122.1
PORTREVISION=	1
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/600/tp1/ \
		ftp://ftp.opera.com/pub/opera/linux/600/tp1/
DISTNAME=	${PORTNAME}-${PORTVERSION}-static_qt.i386

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	${LINUXBASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUXBASE}/usr/X11R6/lib/libXm.so.2:${PORTSDIR}/x11-toolkits/linux-openmotif \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

do-configure:
	${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g; s|%%DATADIR%%|${DATADIR}|g'\
	    ${WRKSRC}/install.sh

do-install:
	(cd ${WRKSRC} && ./install.sh \
	    --exec_prefix=${DATADIR}/bin \
	    --wrapperdir=${PREFIX}/bin \
	    --docdir=${DOCSDIR} \
	    --sharedir=${DATADIR} \
	    --plugindir=${DATADIR}/plugins )
	rmdir ${DATADIR}/uninst/rollback_${PORTVERSION}
	rmdir ${DATADIR}/uninst

.include <bsd.port.mk>
