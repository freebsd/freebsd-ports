# New ports collection makefile for:   htdig
# Date created:        18 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	htdig
PORTVERSION=	3.2.0.b6
CATEGORIES=	textproc www
MASTER_SITES=	http://htdig.sourceforge.net/files/ \
		http://www.htdig.org/files/ \
		http://www.opdenbrouw.nl/htdig/files/ \
		ftp://ftp.ntua.gr/pub/www/htdig/
DISTNAME=	htdig-3.2.0b6

MAINTAINER=	DougB@FreeBSD.org
COMMENT=	A www indexing and searching system

RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/${APACHE_PORT}

USE_LIBTOOL_VER=15

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-config-dir=${PREFIX}/etc/htdig \
		--with-default-config-file=${PREFIX}/etc/htdig/htdig.conf \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-database-dir=${PREFIX}/share/htdig/database \
		--with-cgi-bin-dir=${PREFIX}/www/cgi-bin \
		--with-search-dir=${PREFIX}/www/data \
		--with-image-dir=${PREFIX}/www/icons/htdig \
		--with-image-url-prefix=/icons/htdig \
		--with-ssl \
		--with-apache=${LOCALBASE}/sbin

MAN1=		htdig.1 htdig-pdfparser.1 htdump.1 htfuzzy.1 htload.1 \
		htmerge.1 htnotify.1 htpurge.1 htsearch.1 htstat.1 rundig.1

MAN8=		htdigconfig.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${PATCHDIR}/RELENG_4-patch-htnet_SSLConnection.cc
.endif

pre-install:
.if exists(${PREFIX}/etc/htdig/htdig.conf)
	${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.old
.endif

post-install:
	@${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.sample
.if exists(${PREFIX}/etc/htdig/htdig.conf.old)
	${MV} ${PREFIX}/etc/htdig/htdig.conf.old ${PREFIX}/etc/htdig/htdig.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for f in ChangeLog ChangeLog.0 README STATUS
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in *.html *.gif
	@${INSTALL_DATA} ${WRKSRC}/htdoc/${f} ${DOCSDIR}/html
.endfor
.endif

.include <bsd.port.post.mk>
