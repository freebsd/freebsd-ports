# New ports collection makefile for:	mod_zap Apache module
# Date created:		20 Sep 2000
# Whom:			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	mod_zap
PORTVERSION=	1.4.2
CATEGORIES=	www
MASTER_SITES=	http://ftp.indexdata.dk/pub/zap/
DISTNAME=	zap-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	An Apache module that provides Z39.50 access through WWW

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84
LIB_DEPENDS=	yaz.2:${PORTSDIR}/net/yaz
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/bin/tclsh8.4:${PORTSDIR}/lang/tcl84

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-yazconfig=${LOCALBASE}/bin \
		--with-apxs=${LOCALBASE}/sbin/apxs \
		--with-tclconfig=${LOCALBASE}/lib/tcl8.4

post-install:
		@${MKDIR} ${PREFIX}/share/mod_zap
		@${INSTALL_DATA} ${WRKSRC}/htdocs/zap/* ${PREFIX}/share/mod_zap

.include <bsd.port.mk>
