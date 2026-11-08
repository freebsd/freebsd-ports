PORTNAME=	immich-deduper
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.6
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Find and remove duplicate photos in an Immich library
WWW=		https://github.com/RazgrizHsu/immich-deduper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool \
		${PYTHON_PKGNAMEPREFIX}dash>=4.4.1<5:www/py-dash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dash-bootstrap-components>=2.0.4<3:www/py-dash-bootstrap-components@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.1.3<4:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-caching>=2.5<3:www/py-flask-caching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-socketio>=5.6<6:www/py-flask-socketio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.2.6,1<3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=11.2.1<14:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow-heif>=0.22<2:graphics/py-pillow-heif@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=6.1<8:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.2.3<4:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.1<2:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.11<3:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qdrant-client>=1.16.1<2:databases/py-qdrant-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>=0.26<1:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=4.0.2<7:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=17.1<18:devel/py-websockets@${PY_FLAVOR}

USES=		python:3.12+,run

USE_GITHUB=	yes
GH_ACCOUNT=	RazgrizHsu

USE_RC_SUBR=	immich_deduper

USERS=		immich
GROUPS=		immich

BROKEN_armv7=	misc/py-pytorch does not build on this architecture
BROKEN_i386=	misc/py-pytorch does not build on this architecture

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	immich-deduper pkg-message
SUB_LIST=	DBDIR=${DBDIR} \
		PYTHON_CMD=${PYTHON_CMD}

DBDIR=		/var/db/${PORTNAME}

PLIST_SUB=	DBDIR="${DBDIR}"

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw src ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${SED} -e '/^DEDUP_DATA=/d' ${WRKSRC}/.env.example > \
		${STAGEDIR}${ETCDIR}/deduper.env.sample
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/newsyslog-immich_deduper.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/immich_deduper.conf
	@${MKDIR} ${STAGEDIR}${DBDIR}

.include <bsd.port.mk>
