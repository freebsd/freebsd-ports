# New ports collection makefile for: achievo
# Date created:		19 Jan 2001
# Whom:			mkptools
#
# $FreeBSD$
#

PORTNAME=	achievo
PORTVERSION=	0.4.5
CATEGORIES=	misc www
MASTER_SITES=	ftp://ftp.achievo.com/pub/achievo/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3 \
	${LOCALBASE}/lib/mysql/libmysqlclient.so:${PORTSDIR}/databases/mysql323-client

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
NO_BUILD=	YES

do-install:
	@${MKDIR} ${PREFIX}/www/data.default/achievo
	@${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/achievo/

.include <bsd.port.mk>
