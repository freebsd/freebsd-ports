# New ports collection makefile for:	c-icap-modules
# Date created:				15 August 2012
# Whom:					Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD: ports/www/c-icap/Makefile,v 1.22 2011/09/23 22:25:54 amdmi3 Exp $
#

PORTNAME=	c-icap
PORTVERSION=	0.2.1
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/0.2.x/
PKGNAMESUFFIX=	-modules
DISTNAME=	c_icap_modules-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	c-icap modules virus_scan and srv_url_check

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	icapapi:${PORTSDIR}/www/c-icap \
		clamav:${PORTSDIR}/security/clamav

GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/c_icap

CFLAGS+=	-DHAVE_STRNSTR

MAN8=		c-icap-mods-sguardDB.8

CONFIGURE_ARGS+=	--enable-static \
			--with-c-icap=${LOCALBASE} \
			--with-clamav=${LOCALBASE}

post-install:
	@${CP} -np ${PREFIX}/etc/c-icap/srv_url_check.conf.default \
		${PREFIX}/etc/c-icap/srv_url_check.conf
	@${CP} -np ${PREFIX}/etc/c-icap/virus_scan.conf.default \
		${PREFIX}/etc/c-icap/virus_scan.conf

.include <bsd.port.mk>
