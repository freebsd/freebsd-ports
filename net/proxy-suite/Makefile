# New ports collection Makefile for:	proxy-suite
# Date created:				06 April 2001
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	proxy-suite
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.suse.com/pub/projects/proxy-suite/src/ \
		ftp://ftp.crc.ca/pub/systems/linux/suse/projects/proxy-suite/src/ \
		ftp://ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/src/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.gwdg.de/pub/linux/suse/ftp.suse.com/projects/proxy-suite/src/

MAINTAINER=	thomas@cuivre.fr.eu.org

USE_AUTOCONF=	yes
USE_GMAKE=	yes

#
# basic configure args
#
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libwrap=/usr/lib --with-regex \
		--sysconfdir=${PREFIX}/etc/proxy-suite \
		--localstatedir=/var/run \
		--enable-warnings --enable-so-linger --enable-rfc1579 \
		--disable-proc-mods

#
# OPTIONAL: include ldap-support - currently ldap.2 needs minor fixes...
#
.if defined(WITH_LDAP)
CONFIGURE_ARGS+=	--with-libldap
LIB_DEPENDS+=		ldap.1:${PORTSDIR}/net/openldap
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
	@strip ${WRKSRC}/ftp-proxy/ftp-proxy

.include <bsd.port.mk>
