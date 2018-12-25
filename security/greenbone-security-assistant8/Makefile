# $FreeBSD$

PORTNAME?=	greenbone-security-assistant8
PORTVERSION?=	6.0.12
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES?=	http://wald.intevation.org/frs/download.php/2442/
DISTNAME=	${PORTNAME:S/${OPENVAS_VER}//}-${PORTVERSION}
DIST_SUBDIR=	openvas${OPENVAS_VER}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	OpenVAS 8 web interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt \
		libopenvas_base.so:security/openvas${OPENVAS_VER}-libraries \
		libmicrohttpd.so:www/libmicrohttpd

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/9/}-*

USES=		cmake gettext gnome pkgconfig
USE_GNOME=	glib20 libxml2 libxslt
USE_RC_SUBR=	gsad
ETCDIR=		${PREFIX}/etc/openvas

OPENVAS_VER?=	8

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/gsad_log.conf ${STAGEDIR}${ETCDIR}/gsad_log.conf.sample

.include <bsd.port.mk>
