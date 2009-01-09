# New ports collection makefile for:	libdkim
# Date created:	   03 Oct 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	libdkim
PORTVERSION=	1.0.17
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://duncanthrax.net/exim-experimental/
DISTNAME=	${PORTNAME}-${PORTVERSION}-tk

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DKIM (DomainKeys Identified Mail) library

USE_LDCONFIG=	YES
SHLIB_MAJOR=	1
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

USE_OPENSSL=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include <bsd.port.options.mk>

#Check for OPENSSL 0.9.8 in BASE:  If not present require PORT
.if ${OSVERSION} < 700019
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.pre.mk>

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	@${SED} -e "s=%%SHLIB_MAJOR%%=${SHLIB_MAJOR}=g" \
		${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
