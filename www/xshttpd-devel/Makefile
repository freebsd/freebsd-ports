# New ports collection makefile for:	xshttpd
# Date created:				29 June 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	xshttpd
DISTVERSION=	3.7b23
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/ \
		ftp://mud.stack.nl/pub/xs-httpd/release/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Webserver with CGI as own user and SSL support

RUN_DEPENDS=	run-mailcap:${PORTSDIR}/misc/mime-support \
		ppmtogif:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

CONFLICTS_INSTALL+=	xshttpd-[0-9]* publicfile-[0-9]*

MAN1=		clearxs.1 gfxcount.1 httpd.1 httpdc.1 imagemap.1 \
		readxs.1 xschpass.1 xsindex.1 xspasswd.1
MAN5=		httpd.conf.5 xsauth.5 xsconf.5 xsscripts.5 xsredir.5
MAN7=		httpd_cgi.7 httpd_ssi.7
USE_OPENSSL=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	xshttpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-hier=bsd

OPTIONS_DEFINE=	LDAP CURL M4_CONFIG PERSISTENT_PERL
M4_CONFIG_DESC=	Enable m4 configuration preprocessor
PERSISTENT_PERL_DESC=	Enable persistent perl interpreter

PORTDOCS=	README COPYING ChangeLog

.include <bsd.port.options.mk>
# By default XS-HTTPD stores its data in ${PREFIX}/lib/httpd
WWWDIR?=	${PREFIX}/www/${PORTNAME}

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MM4_CONFIG}
CONFIGURE_ARGS+=--with-preprocessor
.else
CONFIGURE_ARGS+=--without-preprocessor
.endif

.if ${PORT_OPTIONS:MPERSISTENT_PERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-perl
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-curl
.else
CONFIGURE_ARGS+=--without-curl
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|\(MIME_TYPES\).*|\1 "${LOCALBASE}/etc/mime.types"|' \
		-e 's|nobody|${WWWOWN}|' \
		-e 's|nogroup|${WWWGRP}|' \
		-e 's|httpd\.pid|xs&|' \
		${WRKSRC}/src/constants.h
	@${REINPLACE_CMD} -e 's|mime.types ||g' \
		${WRKSRC}/config/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
