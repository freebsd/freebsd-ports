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
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	APACHE DOCS
OPTIONS_DEFAULT=	APACHE

APACHE_USE=	APACHE=22+
APACHE_CONFIGURE_ON=	--with-apache=${LOCALBASE}/sbin
APACHE_PLIST_DIRSTRY=	www/cgi-bin www/data www/icons

PORTDOCS=	*

post-patch:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/htdig/htdig.conf ${STAGEDIR}${PREFIX}/etc/htdig/htdig.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in ChangeLog ChangeLog.0 README STATUS
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in *.html *.gif
	@${INSTALL_DATA} ${WRKSRC}/htdoc/${f} ${STAGEDIR}${DOCSDIR}/html
.endfor

.include <bsd.port.mk>
