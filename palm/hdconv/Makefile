# ports collection makefile for:	hdconv
# Date created:			17 May 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	hdconv
PORTVERSION=	2.01f
CATEGORIES=	palm databases linux
MASTER_SITES=	ftp://ftp.SilberSoft.com/pub/Software/Database/HanDBase/ \
		ftp://ftp.FreeBSD.org/pub/FreeBSD/local-distfiles/knu/
DISTNAME=	handbase_desktop_${PORTVERSION:S/./_/}.i386-any-linux2.0

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${LINUX_DIR}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/handbase-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hd ${PREFIX}/bin/hdconv
	/compat/linux/usr/bin/strip ${PREFIX}/bin/hdconv
	brandelf -t Linux ${PREFIX}/bin/hdconv
	${MKDIR} ${PREFIX}/share/doc/hdconv/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/hdconv/

.include <bsd.port.mk>
