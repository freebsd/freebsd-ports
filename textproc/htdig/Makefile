# New ports collection makefile for:   htdig
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	htdig
PORTVERSION=	3.1.5
CATEGORIES=	textproc www
MASTER_SITES=	http://www.htdig.org/files/ \
		${MASTER_SITE_SUNSITE} \
		ftp://ftp.ntua.gr/pub/www/htdig/ \
		ftp://ftp.max.irk.ru/unix/net/www/ \
		ftp://ftp.loxinfo.co.th/pub/unix/www/ \
		ftp://ftp.htdig.org/pub/htdig/
MASTER_SITE_SUBDIR=	apps/www/indexing

MAINTAINER=	billf@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/doc/apache:${PORTSDIR}/www/apache13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-cgi-bin-dir=${PREFIX}/share/apache/cgi-bin \
		--with-image-dir=${PREFIX}/share/apache/icons \
		--with-search-dir=${PREFIX}/share/apache/htdocs
BUILD_TARGET=	depends all

post-patch:
	@ ${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.Dist
	@ ${SED} -e 's#(CONFIG_DIR)/htdig.conf#(CONFIG_DIR)/htdig.conf.sample#g' \
	${WRKSRC}/Makefile.in.Dist > ${WRKSRC}/Makefile.in

	@ ${MV} ${WRKSRC}/CONFIG.in ${WRKSRC}/CONFIG.in.Dist
	@ ${SED} -e 's#/conf#/etc#' \
		-e 's#/common#/share/htdig#' \
		-e 's#/db#/share/htdig#' \
	${WRKSRC}/CONFIG.in.Dist > ${WRKSRC}/CONFIG.in

	@ ${MV} ${WRKSRC}/CONFIG ${WRKSRC}/CONFIG.Dist
	@ ${SED} -e 's#/conf#/etc#' \
		-e 's#/common#/share/htdig#' \
		-e 's#/db#/share/htdig#' \
	${WRKSRC}/CONFIG.Dist > ${WRKSRC}/CONFIG

.include <bsd.port.mk>
