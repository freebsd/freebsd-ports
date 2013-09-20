# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	htdig
PORTVERSION=	3.2.0.b6
PORTREVISION=	4
CATEGORIES=	textproc www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/3.2.0b6
DISTNAME=	htdig-3.2.0b6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWW indexing and searching system


GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-config-dir=${PREFIX}/etc/htdig \
		--with-default-config-file=${PREFIX}/etc/htdig/htdig.conf \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-database-dir=${PREFIX}/share/htdig/database \
		--with-cgi-bin-dir=${PREFIX}/www/cgi-bin \
		--with-search-dir=${PREFIX}/www/data \
		--with-image-dir=${PREFIX}/www/icons/htdig \
		--with-image-url-prefix=/icons/htdig \
		--with-ssl

MAN1=		htdig.1 htdig-pdfparser.1 htdump.1 htfuzzy.1 htload.1 \
		htmerge.1 htnotify.1 htpurge.1 htsearch.1 htstat.1 rundig.1

MAN8=		htdigconfig.8

OPTIONS_DEFINE=	APACHE DOCS
OPTIONS_DEFAULT=	APACHE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22+
CONFIGURE_ARGS+=	--with-apache=${LOCALBASE}/sbin
.include "${PORTSDIR}/Mk/bsd.apache.mk"
PLIST_DIRSTRY+=	www/cgi-bin www/data www/icons
.endif

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'

pre-install:
.if exists(${PREFIX}/etc/htdig/htdig.conf)
	${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.old
.endif

post-install:
	@${MV} ${PREFIX}/etc/htdig/htdig.conf ${PREFIX}/etc/htdig/htdig.conf.sample
.if exists(${PREFIX}/etc/htdig/htdig.conf.old)
	${MV} ${PREFIX}/etc/htdig/htdig.conf.old ${PREFIX}/etc/htdig/htdig.conf
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/html
.for f in ChangeLog ChangeLog.0 README STATUS
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.for f in *.html *.gif
	@${INSTALL_DATA} ${WRKSRC}/htdoc/${f} ${DOCSDIR}/html
.endfor
.endif

.include <bsd.port.mk>
