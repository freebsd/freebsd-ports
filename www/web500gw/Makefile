# New ports collection makefile for:    web500gw
# Version required:     2.1b2
# Date created:         30 July 1998
# Whom:                 Brent J. Nordquist <bjn@visi.com>
#
# $Id: Makefile,v 1.1.1.1 1998/07/31 18:47:37 nectar Exp $
#

DISTNAME=	web500gw-2.1b2
CATEGORIES=	www net
MASTER_SITES=	ftp://ftp.tu-chemnitz.de/pub/Local/urz/web500gw/ \
		http://www.tu-chemnitz.de/ftp-home/pub/Local/urz/web500gw/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bjn@visi.com

BUILD_DEPENDS=	${PREFIX}/lib/libldap.a:${PORTSDIR}/net/ldap
RUN_DEPENDS=	${INSTDIR}:${PORTSDIR}/www/apache12

INSTDIR=	${PREFIX}/www/cgi-bin

MAKE_ENV=	PLATFORMCFLAGS="${CFLAGS} -DUSE_SYSCONF" \
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

.include <bsd.port.mk>
