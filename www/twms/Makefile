# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twms
PORTVERSION=	0.02w
PORTREVISION=	3
CATEGORIES=	www astro

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tiny WMS server

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyproj>0:graphics/py-pyproj@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/web/__init__.py:www/webpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	Komzpa

USES=		python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	twms.py
NO_BUILD=	yes
NO_ARCH=	yes

TWMS_USER?=	twms
TWMS_GROUP?=	twms
TWMS_CACHEDIR?=	/var/cache/twms

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	USER=${TWMS_USER} GROUP=${TWMS_GROUP} CACHEDIR=${TWMS_CACHEDIR}

USE_RC_SUBR=	twms

USERS=		${TWMS_USER}
GROUPS=		${TWMS_GROUP}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/twms/twms.conf|${PREFIX}/etc/twms.conf|' ${WRKSRC}/twms/twms.py
	@${REINPLACE_CMD} -e '/tiles_cache =/ s|".*"|"${TWMS_CACHEDIR}/cache/"|; \
		/install_path =/ s|".*"|"${DATADIR}/"|; \
		/gpx_cache =/ s|".*"|"${TWMS_CACHEDIR}/traces/"|; \
		s|import fetchers|from twms &|' ${WRKSRC}/twms/twms.conf

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/twms
	${INSTALL_DATA} ${WRKSRC}/twms/*.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/twms/
	${INSTALL_SCRIPT} ${WRKSRC}/twms.py ${STAGEDIR}${PREFIX}/bin/twms
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.jpg ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/twms/twms.conf ${STAGEDIR}${PREFIX}/etc/twms.conf.default

.include <bsd.port.mk>
