# New ports collection makefile for:	mod_zap Apache module
# Date created:		20 Sep 2000
# Whom:			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	mod_zap
PORTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://ftp.indexdata.dk/pub/zap/
DISTNAME=	zap-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
LIB_DEPENDS=	yaz.1:${PORTSDIR}/net/yaz
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yazconfig=${LOCALBASE}/bin \
		--with-apxs=${LOCALBASE}/sbin/apxs

post-install:
		@${MKDIR} ${PREFIX}/share/mod_zap
		@${INSTALL_DATA} ${WRKSRC}/htdocs/zap/* ${PREFIX}/share/mod_zap

.include <bsd.port.mk>
