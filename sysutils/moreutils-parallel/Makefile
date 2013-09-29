# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	moreutils-parallel
PORTVERSION=	0.50
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
MASTER_SITE_SUBDIR=	pool/main/m/moreutils
DISTNAME=	moreutils_${PORTVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Run programs in parallel

LICENSE=	GPLv2

CONFLICTS=	parallel-[0-9]*

WRKSRC=		${WRKDIR}/moreutils

PLIST_FILES=	bin/parallel man/man1/parallel.1.gz

post-patch:
	${CP} ${FILESDIR}/parallel.1 ${WRKSRC}/

do-install:
	${CP} ${WRKSRC}/parallel ${STAGEDIR}${PREFIX}/bin/parallel
	cd ${WRKSRC} && ${INSTALL_MAN} parallel.1 ${STAGEDIR}${MANPREFIX}/man/man1/


.include <bsd.port.mk>
