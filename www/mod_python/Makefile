# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.modpython.org/dist/ \
		http://www.python.org/ftp/python/2.0/ \
		http://www3.kr.freebsd.org/~perky/distfiles/
DISTFILES=	mod_python-${PORTVERSION}.tgz ${PYTHON_DISTFILE}
DIST_SUBDIR=	python

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

USE_PYTHON=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

PYTHON_WRKSRC=	${WRKSRC}/../Python-${PYTHON_VERSION:S/python//g}
APXS=		${PREFIX}/sbin/apxs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs \
		--with-python=${PYTHON_WRKSRC}
CONFIGURE_ENV=	PYTHON_BIN=${LOCALBASE}/bin/python
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

.if defined(WITH_OPENPTY)
OPTIONAL_LIBS+=	-lutil
.endif

.if defined(WITH_GNUREADLINE)
OPTIONAL_LIBS+=	-lreadline
.endif

PYTHON_CONFIGURE_ARGS+=	--without-threads
PYTHON_SETUP_FILE?=	${PORTSDIR}/lang/python/files/Setup
STRIP_BIN?=	    /usr/bin/strip

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build option:"
	@${ECHO} ""
	@${ECHO} "  PYTHON_SETUP_FILE=path  specify python modules setup file"
	@${ECHO} "  WITH_OPENPTY=yes  enables openpty function in posixmodule"
	@${ECHO} "  WITH_GNUREADLINE=yes  enables gnu readline library"
	@${ECHO} "  DONT_STRIP=yes  don't strip shared object"
	@${ECHO} ""

pre-patch:
.if !defined(${WITH_OPENPTY})
	${PATCH} -s <files/optpatch-Python::configure
.endif

pre-configure:
	cd ${PYTHON_WRKSRC} && ./configure ${PYTHON_CONFIGURE_ARGS}
.if !exists(${PYTHON_SETUP_FILE})
	@${ECHO} ""
	@${ECHO} "### COULD NOT FIND PYTHON SETUP FILE"
	@${ECHO} "### SPECIFY FILE PATH OR INSTALL PORT 'lang/python'"
	@${ECHO} ""
.endif

.if !defined(WITH_GNUREADLINE)
	${SED} 's/^readline/#without_readline/g' ${PYTHON_SETUP_FILE} \
		> ${PYTHON_WRKSRC}/Modules/Setup
.else
	${CP} ${PYTHON_SETUP_FILE} ${PYTHON_WRKSRC}/Modules/Setup
.endif

post-configure:
.if defined(OPTIONAL_LIBS)
	${SED} 's/^\(LIBS=.*\)/\1 ${OPTIONAL_LIBS}/' ${WRKSRC}/src/Makefile \
		> ${WRKSRC}/src/Makefile.tmp && \
		${MV} -f ${WRKSRC}/src/Makefile.tmp ${WRKSRC}/src/Makefile
.endif

pre-build:
	cd ${PYTHON_WRKSRC} && ${MAKE}

post-build:
.if !defined(DONT_STRIP) && exists(${STRIP_BIN})
	${STRIP_BIN} ${WRKSRC}/src/mod_python.so
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
