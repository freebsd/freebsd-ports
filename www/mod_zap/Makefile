# New ports collection makefile for:	mod_zap Apache module
# Date created:		20 Sep 2000
# Whom:			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	mod_zap
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.indexdata.dk/pub/yaz/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jeh
DISTNAME=	zap-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/yaz-config:${PORTSDIR}/net/yaz \
		${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/bin/yaz-config:${PORTSDIR}/net/yaz \
		${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yazconfig=${LOCALBASE}/bin \
		--with-apxs=${LOCALBASE}/sbin/apxs

post-install:
		@${MKDIR} ${PREFIX}/share/mod_zap
		@${INSTALL_DATA} ${WRKSRC}/htdocs/zap/* ${PREFIX}/share/mod_zap

.include <bsd.port.mk>
