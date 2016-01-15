# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	htdig
PORTVERSION=	3.2.0.b6
PORTREVISION=	6
CATEGORIES=	textproc www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/3.2.0b6
DISTNAME=	htdig-3.2.0b6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WWW indexing and searching system

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

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
USES=		libtool
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	APACHE DOCS
OPTIONS_DEFAULT=	APACHE

APACHE_USE=	APACHE=22+
APACHE_CONFIGURE_ON=	--with-apache=${LOCALBASE}/sbin

PORTDOCS=	*

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/etc/htdig/htdig.conf ${STAGEDIR}${PREFIX}/etc/htdig/htdig.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for f in ChangeLog ChangeLog.0 README STATUS
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.for f in *.html *.gif
	${INSTALL_DATA} ${WRKSRC}/htdoc/${f} ${STAGEDIR}${DOCSDIR}/html
.endfor

.include <bsd.port.mk>
