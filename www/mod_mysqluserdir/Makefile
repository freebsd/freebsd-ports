# New ports collection makefile for:	mod_mysqluserdir
# Date created:				12 November 2001
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mod_mysqluserdir
PORTVERSION=	0.1
CATEGORIES=	www
MASTER_SITES=	ftp://sys.estpak.ee/pub/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module to make Apache get userdirs from MySQL

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

USE_APACHE=	yes

do-build:
	(cd ${WRKSRC} && ${APXS} -c -I${LOCALBASE}/include \
	-L${LOCALBASE}/lib/mysql -lmysqlclient mod_mysqluserdir.c)

do-install:
	(cd ${WRKSRC} && ${APXS} -i -A -n 'userdir' mod_mysqluserdir.so)
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README ${DOCSDIR}/
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
