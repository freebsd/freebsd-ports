# New ports collection makefile for:	mod_python
# Date created:				28 August 2000
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	mod_python
PORTVERSION=	2.7.8
CATEGORIES=	www python
MASTER_SITES=	http://www.modpython.org/dist/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DIST_SUBDIR=	python
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

NO_PACKAGE=	"Requires Python without threads support"
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ENV=	PYTHON_BIN=${PYTHON_CMD}
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}

STRIP_CMD?=	strip

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build option:"
	@${ECHO} ""
	@${ECHO} "  WANT_EAPI=yes  build as apache EAPI module (for apache13-modssl)"
	@${ECHO} ""

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
