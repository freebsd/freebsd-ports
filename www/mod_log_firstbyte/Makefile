# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_firstbyte
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://mod-log-firstbyte.googlecode.com/svn/trunk/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}.c readme.txt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Log the time between request and the first byte of the response served

BROKEN=		Unfetchable (google code has gone away)

USE_APACHE=	22+

PROJECTHOST=	mod-log-firstbyte
PKGMESSAGE=	${WRKSRC}/readme.txt

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTFILES:S|^|${DISTDIR}/${DIST_SUBDIR}/|} ${WRKSRC}

.include <bsd.port.mk>
