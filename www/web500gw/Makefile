# New ports collection makefile for:    web500gw
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $FreeBSD$
#

PORTNAME=	web500gw
PORTVERSION=	2.1b3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/web500gw/ \
		http://www.tu-chemnitz.de/ftp-home/pub/Local/urz/web500gw/ \
		ftp://ftp.ntua.gr/pub/net/ldap/web500gw/ \
		ftp://ftp.imms.de/pub/unix/networking/ldap/

PATCH_SITES=	http://www.tu-chemnitz.de/~fri/web500gw/
PATCHFILES=	modtmpl.patch

MAINTAINER=	Karl.Dietz@frankfurt.netsurf.de

BUILD_DEPENDS=	${LOCALBASE}/lib/libldap.a:${PORTSDIR}/net/openldap

INSTDIR=	${PREFIX}/bin

MAKE_ENV=	PLATFORMCFLAGS="${CFLAGS} -DUSE_SYSCONF -I${PREFIX}/include" \
		LDFLAGS=-L${PREFIX}/lib \
		INSTDIR=${INSTDIR} \
		WEB500GWDIR=${WEB500GWDIR} \
		MANDIR=${MANPREFIX}/man/man8 \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"
MAN8=		web500gw.8

WEB500GWDIR=	${PREFIX}/etc/web500gw

post-install:
	strip ${INSTDIR}/web500gw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
