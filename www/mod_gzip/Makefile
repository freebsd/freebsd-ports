# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 13 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_gzip
PORTVERSION=	1.3.19.1a
CATEGORIES=	www
MASTER_SITES=	http://www.remotecommunications.com/apache/mod_gzip/src/${PORTVERSION}/
DISTFILES=	${PORTNAME}.c.gz
EXTRACT_ONLY=	${DISTFILES:M*.gz}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

.if !defined(NOPORTDOCS)
DISTFILES+=	changes.txt commands.txt samples.txt
.endif

NO_WRKSUBDIR=	YES

DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_AFTER_ARGS=	> ${PORTNAME}.c

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -A -i ${PORTNAME}.so

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@cd ${_DISTDIR} && ${INSTALL_DATA} ${DISTFILES:N*gz} \
		${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
