# New ports collection makefile for:	mod_mylo
# Date created:				12 November 2001
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_mylo
PORTVERSION=	0.2.1
CATEGORIES=	www
MASTER_SITES=	http://www.pvv.org/~oyving/code/mod_mylo/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

WRKSRC=		${WRKDIR}/${PORTNAME}

APXS=	${LOCALBASE}/sbin/apxs
DOCS=	mod_mylo.sql README

do-build:
	(cd ${WRKSRC} && ${APXS} -c -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib/mysql -lmysqlclient mod_mylo.c)

do-install:
	(cd ${WRKSRC} && ${APXS} -i -A -n 'mylo' mod_mylo.so)
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
