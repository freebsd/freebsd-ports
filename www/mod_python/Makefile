# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang <perky@freebsd-kr.org>
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	2.6
CATEGORIES=	www python
MASTER_SITES=	ftp://freebsd-kr.org/pub/FreeBSD/ \
		http://www.modpython.org/dist/ \
		ftp://ftp.python.org/pub/python/src/ \
		ftp://ftp.cdrom.com/pub/python/www.python.org/ftp/python/src/ \
		http://sunsite.org.uk/Mirrors/ftp.python.org/pub/www.python.org/ftp/python/src/
DISTFILES=      mod_python-${PORTVERSION}.tgz ${PYTHON_DISTFILE}

MAINTAINER=	perky@freebsd-kr.org

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/bin/${PYTHON_VERSION}:${PORTSDIR}/lang/python15
RUN_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

APXS=			${PREFIX}/sbin/apxs
PYTHON_VERSION=		python1.5
PYTHON_NO_DEPENDS=	yes

.if exists(${APXS})
AP_LIBEXEC!=    ${APXS} -q LIBEXEC
.else
AP_LIBEXEC=     ${PREFIX}/libexec/apache
.endif

COMPILEALL=	${PYTHON_LIBDIR}/compileall.py

PLIST_SUB+=	AP_LIBEXEC=${AP_LIBEXEC:S/^${PREFIX}\///} \
		PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR:S/^${PREFIX}\///}"

do-build:
	@${ECHO} "=> Building lib${PYTHON_VERSION}.a for mod_python ..."
	cd ${PYTHON_WRKSRC} && ./configure && ${MAKE} lib${PYTHON_VERSION}.a
	@${ECHO} "=> Building mod_python.so ..."
	cd ${WRKSRC}/src;${APXS} -I../../Python-1.5.2/Include -I../../Python-1.5.2 -I${WRKSRC}/src/include -c mod_python.c -lm ../../Python-1.5.2/lib${PYTHON_VERSION}.a
	${PYTHON_CMD} ${COMPILEALL} ${WRKSRC}/lib/python/mod_python

do-install:
	cd ${WRKSRC}/src;${APXS} -i -a mod_python.so
	${MKDIR} ${PYTHON_SITELIBDIR}/mod_python
	${INSTALL_SCRIPT} ${WRKSRC}/lib/python/mod_python/* ${PYTHON_SITELIBDIR}/mod_python

post-install:
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "  mod_python was installed successfully."
	@${ECHO_MSG} "  please read the manual at http://www.modpython.org"
	@${ECHO_MSG} "======================================================="

.include <bsd.port.mk>
