# New ports collection makefile for:	mod_limitipconn
# Date created:				18 April 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_limitipconn
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dominia.org/djao/limit/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Limit the number of simultaneous connections from a single IP address

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
PLIST_FILES=	${APACHEMODDIR}/mod_limitipconn.so

OPTIONS=	FIXCOUNT "Patch dangling browser connections counting" Off

.include <bsd.port.pre.mk>

.if defined(WITH_FIXCOUNT)
EXTRA_PATCHES+=	${PATCHDIR}/fixcounting.patch
.endif

post-patch:
	${REINPLACE_CMD} -e 's,^APXS = .*,APXS = ${APXS},' ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
