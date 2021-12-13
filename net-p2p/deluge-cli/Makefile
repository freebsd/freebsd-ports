PORTNAME=	deluge
DISTVERSION=	2.0.3
PORTREVISION=	4
CATEGORIES=	net-p2p python
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	-cli

MAINTAINER=	rm@FreeBSD.org
COMMENT=	CLI part of bittorrent client using Python and libtorrent-rasterbar

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	intltool-merge:textproc/intltool \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel \
		${PYTHON_PKGNAMEPREFIX}slimit>0:www/py-slimit
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0.18:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libtorrent-rasterbar>=0:net-p2p/py-libtorrent-rasterbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.8:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=1.0.1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.2.5:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}rencode>0:converters/py-rencode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR}

USES=		cpe gettext python:3.5+
USE_PYTHON=	autoplist distutils

CPE_VENDOR=	deluge-torrent

NO_ARCH=	yes

USE_RC_SUBR=	deluged deluge_web
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CHANGELOG.md README.md

post-patch:
	@${REINPLACE_CMD} -e "/'new_release_check':/s|True,|False,|g ; \
		/'geoip_db_location':/s|/usr/share/GeoIP/GeoIP.dat|${LOCALBASE}/share/GeoIP/GeoIP.dat|g" \
			${WRKSRC}/deluge/core/preferencesmanager.py
	@${REINPLACE_CMD} -e "/'check_new_releases':/s|True,|False,|g ; \
		/'show_new_releases':/s|True,|False,|g" \
			${WRKSRC}/deluge/ui/gtk3/gtkui.py

post-install:
# install man pages
.for man in deluge.1 deluge-console.1 deluge-gtk.1 deluge-web.1 deluged.1
	${INSTALL_MAN} ${WRKSRC}/docs/man/${man} ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
