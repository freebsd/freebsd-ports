# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION= 	2.7.1
CATEGORIES=	www python
MASTER_SITES=	http://www.modpython.org/dist/ \
		http://www.python.org/ftp/python/2.0/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
DISTFILES=      mod_python-${PORTVERSION}.tgz ${PYTHON_DISTFILE}
DIST_SUBDIR=	python

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

PYTHON_WRKSRC=	${WRKSRC}/../Python-${PYTHON_VERSION:S/python//g}
APXS=		${PREFIX}/sbin/apxs

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--with-apxs=${LOCALBASE}/sbin/apxs \
		--with-python=${PYTHON_WRKSRC}
CONFIGURE_ENV=	PYTHON_BIN=${LOCALBASE}/bin/python
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

pre-configure:
	cd ${PYTHON_WRKSRC} && ./configure --without-threads && cd Modules && ${MAKE} -f Makefile.pre Makefile

pre-build:
	cd ${PYTHON_WRKSRC} && ${MAKE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
