# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	moreutils-parallel
PORTVERSION=	0.52
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
MASTER_SITE_SUBDIR=	pool/main/m/moreutils
DISTNAME=	moreutils_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Run programs in parallel

LICENSE=	GPLv2

CONFLICTS=	parallel-[0-9]*

DEPRECATED=	Use moreutils-parallel in sysutils/moreutils instead
EXPIRATION_DATE=2014-09-18

WRKSRC=		${WRKDIR}/moreutils

MAKE_ARGS=	BINS=parallel  MANS=parallel.1

PLIST_FILES=	bin/parallel man/man1/parallel.1.gz

post-patch:
	${CP} ${FILESDIR}/parallel.1 ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/parallel ${STAGEDIR}${PREFIX}/bin/parallel
	cd ${WRKSRC} && ${INSTALL_MAN} parallel.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
