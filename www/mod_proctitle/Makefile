# New ports collection makefile for:	mod_proctitle
# Date created:				15 April 2007
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	mod_proctitle
PORTVERSION=	0.4.1
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.springdaemons.com/soft/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set httpd process titles to reflect currently processed request

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20+
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
CFLAGS+=	-I${LOCALBASE}/include
PLIST_FILES=	${APACHEMODDIR}/${PORTNAME}.so

.include <bsd.port.pre.mk>
.if ${APACHE_VERSION} == 20
CFLAGS+=	-I${LOCALBASE}/include/apr-0
.else
CFLAGS+=	-I${LOCALBASE}/include/apr-1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/mod_proctitle.so \
		${PREFIX}/${APACHEMODDIR}/

.include <bsd.port.post.mk>
