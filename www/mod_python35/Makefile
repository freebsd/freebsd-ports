# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mod_python
PORTVERSION=	3.5.0
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://dist.modpython.org/dist/ \
		LOCAL/ohauer
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	35
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

CONFLICTS_INSTALL=	ap2[24]-mod_python3[^5]*

USES=		apache:2.2+ cpe python:2.7 tar:tgz
CPE_VENDOR=	apache
SUB_FILES=	pkg-message 270_mod_python.conf.sample

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}"		\
			--with-python="${PYTHON_CMD}"	\
			--without-flex

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	APXS=${APXS}
MAKE_ENV=	EXPR_COMPAT=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHON_VER=${PYTHON_VER}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d
	${INSTALL_DATA} ${WRKDIR}/270_mod_python.conf.sample ${STAGEDIR}${PREFIX}/${APACHEETCDIR}/modules.d

# You need to install apache & mod_python before you run this
regression-test: build
	${REINPLACE_CMD} -e 's|%%APACHEMODDIR%%|${APACHEMODDIR}|' ${WRKSRC}/test/test.py
	-@${MAKE} test -C ${WRKSRC}

.include <bsd.port.mk>
