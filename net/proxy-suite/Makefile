# New ports collection Makefile for:	proxy-suite
# Date created:				06 April 2001
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	proxy-suite
PORTVERSION=	1.9.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.suse.com/pub/projects/proxy-suite/src/ \
		ftp://ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/src/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/src/

MAINTAINER=	thomas@cuivre.fr.eu.org
COMMENT=	The SuSE Proxy-Suite, a set of programs to enhance firewall security

USE_AUTOCONF=	yes
WANT_AUTOCONF_VER= 253
USE_GMAKE=	yes

#
# basic configure args
#
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libwrap=/usr/lib --with-regex \
		--localstatedir=/var/run \
		--enable-warnings --enable-so-linger \
		--disable-proc-mods

#
# OPTIONAL: RFC1579 support -- not complete yet.
#
.if defined(WITH_RFC1579)
CONFIGURE_ARGS+= --enable-rfc1579
.endif

#
# OPTIONAL: include ldap-support - currently ldap.2 needs minor fixes...
#
.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-libldap=${LOCALBASE}/lib
LIB_DEPENDS+=		ldap.1:${PORTSDIR}/net/openldap12
.else
CONFIGURE_ARGS+=	--without-libldap
.endif

#
# OPTIONAL: re-build the sgml documentation (postscript, html)
# unfortunatenly this docu it is not up to date :-((
# reading of the manual pages and HOWTO's makes more sense...
#
.if !defined(WITH_SGMLDOC)
ALL_TARGET=	 -C ftp-proxy
.endif

MAN8=		ftp-proxy.8
MAN5=		ftp-proxy.conf.5

pre-install:
	@${STRIP_CMD} ${WRKSRC}/ftp-proxy/ftp-proxy

post-install:
	@${SED} 's|PREFIX|${PREFIX}|' ${PKGMESSAGE}

.include <bsd.port.mk>
