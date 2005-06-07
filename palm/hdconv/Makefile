# ports collection makefile for:	hdconv
# Date created:			17 May 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	hdconv
PORTVERSION=	2.01f
CATEGORIES=	palm databases linux
MASTER_SITES=	# no longer available from original site
DISTNAME=	handbase_desktop_${PORTVERSION:S/./_/}.i386-any-linux2.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts HanDBase database to CSV, and vice versa

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-09-01

BUILD_DEPENDS=	${LINUXBASE}/usr/bin/strip:${PORTSDIR}/devel/linux_devtools-7

USE_LINUX=	7

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/handbase-${PORTVERSION}

PLIST_FILES=	bin/hdconv
PORTDOCS=	README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hd ${PREFIX}/bin/hdconv
	${LINUXBASE}/usr/bin/strip ${PREFIX}/bin/hdconv
	${BRANDELF} -t Linux ${PREFIX}/bin/hdconv
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
