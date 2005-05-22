# New ports collection makefile for:	mod_mylo
# Date created:				12 November 2001
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_mylo
PORTVERSION=	0.2.2
CATEGORIES=	www
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module to make Apache log to MySQL

USE_APACHE=	yes
USE_MYSQL=	YES

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
