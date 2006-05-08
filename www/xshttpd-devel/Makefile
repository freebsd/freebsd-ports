# New ports collection makefile for:	xshttpd
# Date created:				29 June 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	xshttpd
DISTVERSION=	3.4b09
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/ \
		ftp://mud.stack.nl/pub/xs-httpd/release/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@stack.nl
COMMENT=	A webserver with CGI as own user and SSL suport

RUN_DEPENDS=	run-mailcap:${PORTSDIR}/misc/mime-support

CONFLICTS+=	apache-[0-9]* xshttpd-[0-9]*

MAN1=		clearxs.1 gfxcount.1 httpd.1 httpdc.1 imagemap.1 \
		readxs.1 xsindex.1 xspasswd.1
MAN5=		httpd.conf.5 xsauth.5 xsscripts.5
USE_BZIP2=	yes
USE_RC_SUBR=	xshttpd.sh

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	SSL "Enable https support" On \
		LDAP "Enable ldap support" Off \
		PCRE "Enable pcre rewriting support" Off \
		PERSISTENT_PERL "Enable persistent perl interpreter" Off

PORTDOCS=	README BUGS COPYING ChangeLog

# By default XS-HTTPD stores its data in ${PREFIX}/lib/httpd
WWWDIR?=	${PREFIX}/www
PLIST_SUB=	WWWDIR=${WWWDIR:S,^${PREFIX}/,,}
CONFIGURE_ARGS+=--with-rootdir=${WWWDIR}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SSL)
.include <${PORTSDIR}/Mk/bsd.openssl.mk>
#USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-ldap
.endif

.if defined(WITH_PERSISTENT_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-perl
.else
CONFIGURE_ARGS+=--without-perl
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=--with-pcre=yes
.else
CONFIGURE_ARGS+=--with-pcre=no
.endif

post-patch:
.for i in man/httpd.1 man/httpd.conf.5 config/httpd.conf.sample \
	contrib/SSL-Makefile contrib/logrotate.sh
	@${REINPLACE_CMD} \
		-e 's|/wwwsys|${WWWDIR}|g' \
		-e 's|/usr/local/lib/httpd|${WWWDIR}|g' \
		-e 's|nobody|${WWWOWN}|g' \
		-e 's|nogroup|${WWWGRP}|g' \
		${WRKSRC}/$i
.endfor
	@${REINPLACE_CMD} -e 's|\(MIMETYPESFILE\ "\).*|\1${LOCALBASE}/etc/mime.types"|' \
		${WRKSRC}/src/confuser.h
	@${REINPLACE_CMD} -e 's|mime.types ||g' \
		${WRKSRC}/config/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.post.mk>
