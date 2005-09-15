# New ports collection makefile for:	xshttpd
# Date created:				29 June 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	xshttpd
DISTVERSION=	3.3b26
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.stack.nl/pub/xs-httpd/release/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/.//}

MAINTAINER=	johans@stack.nl
COMMENT=	A webserver with CGI as own user and SSL suport

CONFLICTS+=	apache-[0-9]*

GNU_CONFIGURE=	yes

MAN1=		clearxs.1 gfxcount.1 httpd.1 httpdc.1 imagemap.1 \
		readxs.1 xsindex.1 xspasswd.1
MAN5=		httpd.conf.5 xsauth.5 xsscripts.5
USE_RC_SUBR=	xshttpd.sh

# By default XS-HTTPD stores its data in ${PREFIX}/lib/httpd
DATADIR=	${PREFIX}/www
CONFIGURE_ARGS+=--with-rootdir=${DATADIR}

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
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
.for i in "man/httpd.1" "man/httpd.conf.5" "config/httpd.conf.sample" \
	"contrib/SSL-Makefile" "contrib/logrotate.sh"
	@${SED} \
		-e 's|/wwwsys|${DATADIR}|g' \
		-e 's|/usr/local/lib/httpd|${DATADIR}|g' \
		${WRKSRC}/$i > ${WRKSRC}/$i.tmp
	@${MV} ${WRKSRC}/$i.tmp ${WRKSRC}/$i
.endfor

.include <bsd.port.mk>
