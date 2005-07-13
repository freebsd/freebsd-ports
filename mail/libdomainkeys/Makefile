# New ports collection makefile for:	libdomainkeys
# Date created:	   16 May 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	libdomainkeys
PORTVERSION=	0.66
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	domainkeys

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DomainKeys library

MAKE_ENV=	PREFIX=${PREFIX} OPENSSLBASE="${OPENSSLBASE}"
INSTALLS_SHLIB=	YES
SHLIB_MAJOR=	2
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

USE_OPENSSL=	YES

.if defined(NOPROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	@${SED} -e "s=%%SHLIB_MAJOR%%=${SHLIB_MAJOR}=g" \
		${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include <bsd.port.mk>
