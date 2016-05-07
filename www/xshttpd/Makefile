# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	xshttpd
DISTVERSION=	3.6g01
PORTREVISION=	9
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/ \
		ftp://mud.stack.nl/pub/xs-httpd/release/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Webserver with CGI as own user and SSL support

BROKEN_powerpc64=	Does not build

RUN_DEPENDS=	run-mailcap:misc/mime-support \
		ppmtogif:graphics/netpbm

CONFLICTS_INSTALL=	xshttpd-devel-[0-9]* publicfile-[0-9]*

USES=	tar:bzip2
USE_RC_SUBR=	xshttpd
GNU_CONFIGURE=	yes

WWWDIR=		${PREFIX}/www/${PORTNAME}
CONFIGURE_ARGS+=--with-rootdir=${WWWDIR}

OPTIONS_DEFINE=	SSL PCRE LDAP CURL M4_CONFIG PERSISTENT_PERL
OPTIONS_DEFAULT=SSL PCRE
SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_WITH=	ssl
LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap
M4_CONFIG_DESC=	Enable m4 configuration preprocessor
M4_CONFIG_CONFIGURE_WITH=preprocessor
PERSISTENT_PERL_DESC=	Enable persistent Perl interpreter
PERSISTENT_PERL_USES=	perl5
PERSISTENT_PERL_CONFIGURE_WITH=	perl
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl

PORTDOCS=	README ChangeLog

post-patch:
.for i in man/httpd.1.in man/httpd.conf.5 config/httpd.conf.sample \
	contrib/SSL-Makefile contrib/logrotate.sh
	@${REINPLACE_CMD} \
		-e 's|/wwwsys|${WWWDIR}|g' \
		-e 's|/usr/local/lib/httpd|${WWWDIR}|g' \
		-e 's|nobody|${WWWOWN}|g' \
		-e 's|nogroup|${WWWGRP}|g' \
		${WRKSRC}/$i
.endfor
	@${REINPLACE_CMD} \
		-e 's|\(MIME_TYPES\).*|\1 "${LOCALBASE}/etc/mime.types"|' \
		${WRKSRC}/src/constants.h
	@${REINPLACE_CMD} -e 's|mime.types ||g' \
		${WRKSRC}/config/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${WWWDIR}/htdocs
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
