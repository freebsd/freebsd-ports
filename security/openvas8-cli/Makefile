# $FreeBSD$

PORTNAME?=	openvas8-cli
PORTVERSION?=	1.4.5
CATEGORIES=	security
MASTER_SITES?=	http://wald.intevation.org/frs/download.php/2397/
DISTNAME=	${PORTNAME:S/${OPENVAS_VER}//}-${PORTVERSION}
DIST_SUBDIR=	openvas${OPENVAS_VER}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	OpenVAS 8 command-line interface and Nagios plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libopenvas_base.so:security/openvas${OPENVAS_VER}-libraries

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/9/}-*

CFLAGS+=	-Wno-missing-field-initializers
USES=		cmake gnome pkgconfig shebangfix
SHEBANG_FILES=	dialog/omp-dialog
USE_GNOME=	glib20 libxslt:run

OPENVAS_VER?=	8

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${MV} ${STAGEDIR}${PREFIX}/bin/check_omp \
		${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
