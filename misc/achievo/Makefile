# New ports collection makefile for: achievo
# Date created:		19 Jan 2001
# Whom:			mkptools
#
# $FreeBSD$
#

PORTNAME=	achievo
PORTVERSION=	0.8.4
CATEGORIES=	misc www
MASTER_SITES=	http://ftp.achievo.org/pub/achievo/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	YES

do-install:
	@${MKDIR} ${PREFIX}/www/data.default/achievo
	@${CP} -R ${WRKSRC}/* ${PREFIX}/www/data.default/achievo/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
