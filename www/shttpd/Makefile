# New ports collection makefile for:  shttpd
# Date created:			  Wed Dec 15, 2004
# Whom:				  Sergey Lyubka (valenok@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	shttpd
PORTVERSION=	1.17
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	shttpd
DISTNAME=	shttpd_${PORTVERSION}.c
EXTRACT_SUFX=
EXTRACT_ONLY=	#none

MAINTAINER=	valenok@gmail.com
COMMENT=	Simple embeddable web server with CGI support

NO_WRKSUBDIR=	yes
DIST_SUBDIR=	${PORTNAME}
MAN1=		shttpd.1

.if defined(WITHOUT_SSL)
PKGNAMESUFFIX=	-nossl
.else
CFLAGS+=	-DWITH_SSL -lssl -lcrypto
.endif

PLIST_FILES=	bin/shttpd

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}/

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/shttpd ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shttpd ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/shttpd.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
