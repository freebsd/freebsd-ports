# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	xshttpd
DISTVERSION=	3.7b35
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/ \
		ftp://mud.stack.nl/pub/xs-httpd/release/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Webserver with CGI as own user and SSL support

RUN_DEPENDS=	run-mailcap:misc/mime-support
LIB_DEPENDS=	libpcre.so:devel/pcre

CONFLICTS_INSTALL=	xshttpd-[0-9]* publicfile-[0-9]*

USES=		tar:bzip2
USE_OPENSSL=	yes
USE_RC_SUBR=	xshttpd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-hier=bsd --with-userid=${WWWOWN}:${WWWGRP}

OPTIONS_DEFINE=		BDB CURL LDAP M4 NETPBM PERL
OPTIONS_DEFAULT=	BDB CURL M4 NETPBM
OPTIONS_SUB=		yes
BDB_USE=		BDB=5+
BDB_CONFIGURE_ON=	--with-db-libdir=${BDB_LIB_DIR} \
			--with-db-include-dir=${BDB_INCLUDE_DIR}
BDB_CONFIGURE_WITH=	db
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl
LDAP_USE=		openldap
LDAP_CONFIGURE_WITH=	ldap
M4_DESC=		Enable configuration preprocessor (m4)
M4_CONFIGURE_WITH=	preprocessor
NETPBM_DESC=		Enable NETPBM (for graphical counters)
NETPBM_RUN_DEPENDS=	ppmtogif:graphics/netpbm
PERL_DESC=		Enable persistent Perl interpreter
PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl

PORTDOCS=	README ChangeLog

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(MIME_TYPES\).*|\1 "${LOCALBASE}/etc/mime.types"|' \
		${WRKSRC}/src/constants.h
	@${REINPLACE_CMD} -e 's|mime.types ||g' \
		${WRKSRC}/config/Makefile.in
	@${REINPLACE_CMD} -e '/libdir/ s|(INSTALL_DATA)|& -s|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's/$$(htmldir)/$$(DESTDIR)&/' \
		${WRKSRC}/contrib/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${WWWDIR}/htdocs \
		${STAGEDIR}/var/log/xshttpd \
		${STAGEDIR}/var/db/xshttpd/sessions
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
