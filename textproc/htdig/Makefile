# New ports collection makefile for:   htdig
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	htdig
PORTVERSION=	3.1.6
CATEGORIES=	textproc www
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.ntua.gr/pub/www/htdig/

MAINTAINER=	DougB@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/doc/apache:${PORTSDIR}/www/apache13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/share/apache/cgi-bin \
		--with-image-dir=${PREFIX}/share/apache/icons/htdig \
		--with-search-dir=${PREFIX}/share/apache/htdocs \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-database-dir=${PREFIX}/share/htdig/database \
		--with-config-dir=${PREFIX}/etc/htdig \
		--with-default-config-file=${PREFIX}/etc/htdig/htdig.conf

BUILD_TARGET=	depends all

post-patch:
.for file in CONFIG CONFIG.in
	@ ${CP} ${WRKSRC}/${file} ${WRKSRC}/${file}.Dist
	@ ${SED} -e 's#/conf#/etc#' \
		-e 's#/common#/share/htdig#' \
		-e 's#/db#/share/htdig#' \
	${WRKSRC}/${file}.Dist > ${WRKSRC}/${file}
.endfor
.for file in dist/configure dist/configure.in docs/ref/program/thread.html
	@ ${CP} ${WRKSRC}/db/${file} ${WRKSRC}/db/${file}.Dist
	@ ${SED} -e 's#-lc_r#${PTHREAD_LIBS:S/"//g}#g' \
		${WRKSRC}/db/${file}.Dist > ${WRKSRC}/db/${file}
.endfor

post-install:
	@ ${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.sample

.include <bsd.port.mk>
