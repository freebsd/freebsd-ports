# New ports collection makefile for:    mod_sqlinclude
# Date created:				October 25 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$

PORTNAME=	mod_sqlinclude
PORTVERSION=	1.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	An Apache module implementing config inclusion from MySQL databases

USE_MYSQL=	yes
DOCS=		CHANGES.txt README.txt test.sql

.if defined(WITH_APACHE2) || exists(${LOCALBASE}/include/apache2/apr.h)
IGNORE=		Sorry, mod_sqlinclude only works with Apache 1.x
.else
USE_APACHE=	yes
.endif

do-build:
	(cd ${WRKSRC} && ${APXS} -c -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib/mysql -lmysqlclient mod_sqlinclude.c)

do-install:
	(cd ${WRKSRC} && ${APXS} -i -A -n 'sqlinclude' mod_sqlinclude.so)
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
