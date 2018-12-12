# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME?=	openvas8-scanner
PORTVERSION?=	5.0.8
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES?=	http://wald.intevation.org/frs/download.php/2436/
DISTNAME=	${PORTNAME:S/${OPENVAS_VER}//}-${PORTVERSION}
DIST_SUBDIR=	openvas${OPENVAS_VER}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	OpenVAS 8 scanner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libopenvas_base.so:security/openvas${OPENVAS_VER}-libraries
RUN_DEPENDS=	redis-server:databases/redis \
		curl:ftp/curl \
		rsync:net/rsync \
		wget:ftp/wget \
		nmap:security/nmap

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/9/}-*

USES=		cmake:outsource gettext-runtime gnome pkgconfig
USE_GNOME=	glib20
USE_RC_SUBR=	openvassd
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/${OPENVAS_VER}//}

OPENVAS_VER?=	8

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
