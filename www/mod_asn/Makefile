# $FreeBSD$

PORTNAME=	mod_asn
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://mirrorbrain.org/files/releases/
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Look up the AS and network prefix of IP address

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:${PORTSDIR}/devel/apr1

USE_APACHE=	22
AP_FAST_BUILD=	yes
MANUAL_PACKAGE_BUILD=	devel/apr1 with pgsql option required

.include <bsd.port.pre.mk>

pre-build:
	@[ -r ${PREFIX}/lib/apr-util-1/apr_dbd_pgsql.so ] || (${ECHO_MSG} "APR util with PostgreSQL required."; ${FALSE})

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asn_import.py ${STAGEDIR}${PREFIX}/bin/asn_import
	${INSTALL_SCRIPT} ${WRKSRC}/asn_get_routeviews.py ${STAGEDIR}${PREFIX}/bin/asn_get_routeviews
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/asn.sql ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mod_asn.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
