# $FreeBSD$

PORTNAME?=	openvas8-manager
PORTVERSION?=	6.0.11
CATEGORIES=	security
MASTER_SITES?=	http://wald.intevation.org/frs/download.php/2445/
DISTNAME=	${PORTNAME:S/${OPENVAS_VER}//}-${PORTVERSION}
DIST_SUBDIR=	openvas${OPENVAS_VER}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	OpenVAS 8 manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libgcrypt.so:security/libgcrypt \
		libopenvas_base.so:security/openvas${OPENVAS_VER}-libraries

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/9/}-*

USES=		cmake:outsource execinfo gnome pkgconfig sqlite
USE_GNOME=	glib20
USE_RC_SUBR=	openvasmd
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/${OPENVAS_VER}//}
REINPLACE_ARGS=	-i ''

OPENVAS_VER?=	8

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/tools/extra/xml_split

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
