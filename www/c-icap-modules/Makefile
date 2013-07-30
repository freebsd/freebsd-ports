# Created by: Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	c-icap
PORTVERSION=	0.2.4
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/0.2.x/
PKGNAMESUFFIX=	-modules
DISTNAME=	c_icap_modules-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	c-icap modules virus_scan and srv_url_check

LICENSE=	GPLv2

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
		${PREFIX}/etc/c-icap/srv_url_check.conf || ${TRUE}
	@${CP} -np ${PREFIX}/etc/c-icap/virus_scan.conf.default \
		${PREFIX}/etc/c-icap/virus_scan.conf || ${TRUE}

.include <bsd.port.mk>
