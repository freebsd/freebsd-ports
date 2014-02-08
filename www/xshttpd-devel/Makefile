# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	xshttpd
DISTVERSION=	3.7b27
PORTREVISION=	2
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/ \
		ftp://mud.stack.nl/pub/xs-httpd/release/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Webserver with CGI as own user and SSL support

RUN_DEPENDS=	run-mailcap:${PORTSDIR}/misc/mime-support \
		ppmtogif:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS_INSTALL=	xshttpd-[0-9]* publicfile-[0-9]*

USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	xshttpd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-hier=bsd

OPTIONS_DEFINE=		LDAP CURL M4 PERL
OPTIONS_SUB=		yes
LDAP_USE=		openldap
LDAP_CONFIGURE_WITH=	ldap
M4_DESC=		Enable configuration preprocessor (m4)
M4_CONFIGURE_WITH=	preprocessor
PERL_DESC=		Enable persistent Perl interpreter
PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl
CURL_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
CURL_CONFIGURE_WITH=	curl

PORTDOCS=	README ChangeLog

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(MIME_TYPES\).*|\1 "${LOCALBASE}/etc/mime.types"|' \
		-e 's|nobody|${WWWOWN}|' \
		-e 's|nogroup|${WWWGRP}|' \
		-e 's|httpd\.pid|xs&|' \
		${WRKSRC}/src/constants.h
	@${REINPLACE_CMD} -e 's|mime.types ||g' \
		${WRKSRC}/config/Makefile.in
# Fix parallel builds (-jX): all programs must depend on the library
	@${ECHO_CMD} '$$(bin_PROGRAMS) $$(phexec_PROGRAMS)' \
		'$$(noinst_PROGRAMS): $$(noinst_LIBRARIES)' \
			>> ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/libdir/ s|(INSTALL_DATA)|& -s|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${WWWDIR}/htdocs
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
