# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 13 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_gzip
PORTVERSION=	1.3.14.6e
CATEGORIES=	www
MASTER_SITES=	http://12.17.228.52/mod_gzip/src/${PORTVERSION}/
DISTFILES=	${PORTNAME}.c.gz
EXTRACT_ONLY=	${DISTFILES:M*.gz}

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

.if !defined(NOPORTDOCS)
DISTFILES+=	readme.txt
.endif

NO_WRKSUBDIR=	YES

DIST_SUBDIR=	${PORTNAME}
EXTRACT_AFTER_ARGS=	> ${PORTNAME}.c

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -A -i ${PORTNAME}.so

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${_DISTDIR}/${DISTFILES:N*gz} \
		${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
