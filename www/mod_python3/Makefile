# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	2.7.3
CATEGORIES=	www python
MASTER_SITES=	http://www.python.org/ftp/python/${PYTHON_VERSION:S/python//g}/ \
		http://www.modpython.org/dist/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
DISTFILES=	mod_python-${PORTVERSION}.tgz ${PYTHON_DISTFILE}
DIST_SUBDIR=	python

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

USE_PYTHON=	yes

.include <bsd.port.pre.mk>

PYTHON_WRKSRC=	${WRKSRC}/../Python-${PYTHON_VERSION:S/python//g}
APXS=		${PREFIX}/sbin/apxs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-apxs=${APXS} --with-python=${PYTHON_WRKSRC}
CONFIGURE_ENV=	PYTHON_BIN=${PYTHON_CMD}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

.if defined(WITH_OPENPTY)
OPTIONAL_LIBS+=	-lutil
.endif

PYTHON_CONFIGURE_ARGS+=	--without-threads
STRIP_CMD?=	strip

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build option:"
	@${ECHO} ""
	@${ECHO} "  WANT_EAPI=yes  build as apache EAPI module (for apache13-modssl)"
	@${ECHO} "  WITH_OPENPTY=yes  enables openpty function in posixmodule"
	@${ECHO} ""

pre-patch:
.if !defined(WITH_OPENPTY)
	${PATCH} -s < ${PATCHDIR}/optpatch-WITHOUT_OPENPTY
.endif
.if defined(WANT_EAPI)
	${PATCH} -s < ${PATCHDIR}/optpatch-WANT_EAPI
.endif

pre-configure:
	cd ${PYTHON_WRKSRC} && ./configure ${PYTHON_CONFIGURE_ARGS}

post-configure:
.if defined(OPTIONAL_LIBS)
	${SED} 's/^\(LIBS=.*\)/\1 ${OPTIONAL_LIBS}/' ${WRKSRC}/src/Makefile \
		> ${WRKSRC}/src/Makefile.tmp && \
		${MV} -f ${WRKSRC}/src/Makefile.tmp ${WRKSRC}/src/Makefile
.endif

pre-build:
	cd ${PYTHON_WRKSRC} && ${MAKE}

post-build:
.if !defined(DONT_STRIP) && exists(${STRIP_CMD})
	${STRIP_CMD} ${WRKSRC}/src/mod_python.so
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
