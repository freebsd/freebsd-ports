# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	c-icap
PORTVERSION=	0.3.2
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/0.3.x/
PKGNAMESUFFIX=	-modules
DISTNAME=	c_icap_modules-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	c-icap modules virus_scan and srv_url_check

LICENSE=	GPLv2

LIB_DEPENDS+=	icapapi.3:${PORTSDIR}/www/c-icap \
		clamav:${PORTSDIR}/security/clamav

GNU_CONFIGURE=	yes
DATADIR=	${PREFIX}/share/c_icap

CFLAGS+=	-DHAVE_STRNSTR

MAN8=		c-icap-mods-sguardDB.8

CONFIGURE_ARGS+=	--enable-static \
			--with-c-icap=${LOCALBASE} \
			--with-clamav=${LOCALBASE}

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/c-icap

post-install:
	@${CP} -np ${STAGEDIR}${PREFIX}/etc/c-icap/clamav_mod.conf.default \
		${STAGEDIR}${PREFIX}/etc/c-icap/clamav_mod.conf || ${TRUE}
	@${CP} -np ${STAGEDIR}${PREFIX}/etc/c-icap/clamd_mod.conf.default \
		${STAGEDIR}${PREFIX}/etc/c-icap/clamd_mod.conf || ${TRUE}
	@${CP} -np ${STAGEDIR}${PREFIX}/etc/c-icap/srv_url_check.conf.default \
		${STAGEDIR}${PREFIX}/etc/c-icap/srv_url_check.conf || ${TRUE}
	@${CP} -np ${STAGEDIR}${PREFIX}/etc/c-icap/virus_scan.conf.default \
		${STAGEDIR}${PREFIX}/etc/c-icap/virus_scan.conf || ${TRUE}

.include <bsd.port.mk>
