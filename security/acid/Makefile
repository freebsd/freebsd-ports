# New ports collection makefile for:	acid
# Date created:		Mon Sep 25 16:05:01 CST 2000
# Whom:			Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acid
PORTVERSION=	0.9.6b21
CATEGORIES=	security
MASTER_SITES=	http://www.andrew.cmu.edu/~rdanyliw/snort/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Analysis Console for Intrusion Databases (ACID) with Snort and MySQL

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4 \
		${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql323-server \
		${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort \
		${LOCALBASE}/www/data.default/php/adodb:${PORTSDIR}/databases/adodb

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/www/acid
.for ext in html php sql css inc
	@${INSTALL_DATA} ${WRKSRC}/*.${ext} ${PREFIX}/www/acid
.endfor
.ifndef(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/www/acid
	@${INSTALL_DATA} ${WRKSRC}/README.mssql ${PREFIX}/www/acid
.endif

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.mk>
