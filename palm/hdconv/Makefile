# ports collection makefile for:	hdconv
# Date created:			17 May 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	hdconv
PORTVERSION=	2.01f
CATEGORIES=	palm databases linux
MASTER_SITES=	ftp://ftp.SilberSoft.com/pub/Software/Database/HanDBase/
DISTNAME=	handbase_desktop_${PORTVERSION:S/./_/}.i386-any-linux2.0

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Converts HanDBase database to CSV, and vice versa

BUILD_DEPENDS=	${LINUXBASE}/usr/bin/strip:${PORTSDIR}/devel/linux_devtools-7

USE_LINUX=	yes

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/handbase-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hd ${PREFIX}/bin/hdconv
	${LINUXBASE}/usr/bin/strip ${PREFIX}/bin/hdconv
	brandelf -t Linux ${PREFIX}/bin/hdconv
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/hdconv/
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/hdconv/
.endif

.include <bsd.port.mk>
