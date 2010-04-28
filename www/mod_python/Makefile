# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	2.7.11
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	modpython
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	python

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache 1.3 module for integrating Python

.if defined(PACKAGE_BUILDING)
IGNORE=	Requires python WITHOUT_THREADS
.endif

USE_APACHE=	13
NO_PACKAGE=	Requires Python without threads support
USE_PYTHON=	yes

PORTSCOUT=	limit:^2

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ENV=	PYTHON_BIN=${PYTHON_CMD}
MAKE_ENV=	PORTS_APXS=${APXS}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Note that this is for Apache 1.3 only, use www/mod_python 3 for Apache 2.x"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WANT_EAPI=yes  build as apache EAPI module (for apache13-modssl)"
	@${ECHO_MSG} ""

pre-patch:
.if defined(WANT_EAPI)
	cd ${WRKSRC} && ${PATCH} -p2 -s < ${PATCHDIR}/optpatch-WANT_EAPI
.endif

post-configure:
	@${SH} ${PKGREQ}.threads ${PYTHON_CMD}
.if defined(OPTIONAL_LIBS)
	${SED} 's/^\(LIBS=.*\)/\1 ${OPTIONAL_LIBS}/' ${WRKSRC}/src/Makefile \
		> ${WRKSRC}/src/Makefile.tmp && \
		${MV} -f ${WRKSRC}/src/Makefile.tmp ${WRKSRC}/src/Makefile
.endif

post-build:
.if !defined(DONT_STRIP) && exists(${STRIP_CMD})
	${STRIP_CMD} ${WRKSRC}/src/mod_python.so
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
