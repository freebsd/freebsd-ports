# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pscan
PORTVERSION=	1.3
CATEGORIES=	security devel
MASTER_SITES=	http://deployingradius.com/pscan/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Security C code scanner for misuse of format strings

ALL_TARGET=	#empty
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/pscan bin/find_formats

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pscan ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/find_formats.sh \
		${STAGEDIR}${PREFIX}/bin/find_formats

.include <bsd.port.mk>
