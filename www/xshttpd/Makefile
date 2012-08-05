# New ports collection makefile for:	xshttpd
# Date created:				29 June 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	xshttpd
DISTVERSION=	3.6g01
PORTREVISION=	5
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/ \
		ftp://mud.stack.nl/pub/xs-httpd/release/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Webserver with CGI as own user and SSL support

RUN_DEPENDS=	run-mailcap:${PORTSDIR}/misc/mime-support \
		ppmtogif:${PORTSDIR}/graphics/netpbm

CONFLICTS_INSTALL+=	xshttpd-devel-[0-9]* publicfile-[0-9]*

MAN1=		clearxs.1 gfxcount.1 httpd.1 httpdc.1 imagemap.1 \
		readxs.1 xschpass.1 xsindex.1 xspasswd.1
MAN5=		httpd.conf.5 xsauth.5 xsconf.5 xsscripts.5 xsredir.5
MAN7=		httpd_cgi.7 httpd_ssi.7
USE_BZIP2=	yes
USE_RC_SUBR=	xshttpd

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	SSL PCRE LDAP CURL M4_CONFIG PERSISTENT_PERL
OPTIONS_DEFAULT=SSL PCRE
M4_CONFIG_DESC=	Enable m4 configuration preprocessor
PERSISTENT_PERL_DESC=	Enable persistent perl interpreter

PORTDOCS=	README COPYING ChangeLog

.include <bsd.port.options.mk>
# By default XS-HTTPD stores its data in ${PREFIX}/lib/httpd
WWWDIR?=	${PREFIX}/www/${PORTNAME}
CONFIGURE_ARGS+=--with-rootdir=${WWWDIR}

.if ${PORT_OPTIONS:MSSL}
.include <${PORTSDIR}/Mk/bsd.openssl.mk>
#USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-ldap
.endif

.if ${PORT_OPTIONS:MM4_CONFIG}
CONFIGURE_ARGS+=--with-preprocessor
.else
CONFIGURE_ARGS+=--without-preprocessor
.endif

.if ${PORT_OPTIONS:MPERSISTENT_PERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-perl
.else
CONFIGURE_ARGS+=--without-perl
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre=yes
.else
CONFIGURE_ARGS+=--with-pcre=no
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-curl=yes
.else
CONFIGURE_ARGS+=--with-curl=no
.endif

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
