PORTNAME=	mod_wsgi
DISTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Python WSGI adapter module for Apache
WWW=		https://www.modwsgi.org/

LICENSE=	APACHE20

USES=		apache autoreconf cpe python
USE_PYTHON=	flavors

CPE_VENDOR=	modwsgi

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}" \
			--with-python="${PYTHON_CMD}"

SUB_FILES=	${APMOD_FILE}
APMOD_FILE=	270_${PORTNAME}.conf.sample
PLIST_SUB+=	APMOD_FILE=${APMOD_FILE}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/${APMOD_FILE} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so

.include <bsd.port.mk>
