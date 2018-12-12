# Created by: teramoto@comm.eng.osaka-u.ac.jp
# $FreeBSD$

PORTNAME=	gpgme
PORTVERSION=	1.12.0
PORTREVISION?=	2
CATEGORIES?=	security
MASTER_SITES=	GNUPG/gpgme

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Library to make access to GnuPG easier

LICENSE?=	LGPL21+
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error

USES=		cpe gmake libtool localbase:ldflags tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CPE_VENDOR=	gnu

.if !defined(SLAVEPORT)
CONFIGURE_ARGS+=--enable-languages="cl"

INFO=		gpgme
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README THANKS TODO

OPTIONS_DEFINE=		DOCS TEST UISERVER
OPTIONS_SINGLE=		GNUPG
OPTIONS_SINGLE_GNUPG=	GNUPG1 GNUPG2
OPTIONS_DEFAULT=	GNUPG2 UISERVER

GNUPG1_DESC=		Build gpgme library for GnuPG 1.x
GNUPG1_BUILD_DEPENDS=	gpgv:security/gnupg1
GNUPG1_RUN_DEPENDS=	gpgv:security/gnupg1

GNUPG2_DESC=		Build gpgme library for GnuPG 2.x
GNUPG2_BUILD_DEPENDS=	gpg2:security/gnupg
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg

TEST_CONFIGURE_ENABLE=	g13-test gpg-test gpgconf-test gpgsm-test
TEST_PREVENTS=		GNUPG1
TEST_PREVENTS_MSG=	TEST option is mainly designed for use with the GNUPG2 option

UISERVER_DESC=			GnuPG UI server support
UISERVER_CONFIGURE_ENABLE=	fd-passing
.else
LIB_DEPENDS+=	libgpgme.so:security/gpgme
BUILD_WRKSRC=	${WRKSRC}/lang/${BINDING_NAME}
INSTALL_WRKSRC=	${WRKSRC}/lang/${BINDING_NAME}
TEST_WRKSRC=	${WRKSRC}/lang/${BINDING_NAME}/tests

.  if ${SLAVEPORT} != "cpp"
OPTIONS_DEFINE+=	TEST
.  endif

.  if ${SLAVEPORT} == "cpp"
USES+=		compiler:c++11-lib
CONFIGURE_ARGS+=--enable-languages="cpp"
NO_TEST=	yes
.  endif

.  if ${SLAVEPORT} == "qt5"
LIB_DEPENDS+=	libgpgmepp.so:security/gpgme-cpp
USES+=		compiler:c++11-lib pkgconfig qt:5
USE_QT=	buildtools_build core
CONFIGURE_ARGS+=--enable-languages="cpp qt"
DOCSDIR=	${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE+=	DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
TEST_USE=		QT=testlib_build
.  endif

.  if ${SLAVEPORT} == "python"
BUILD_DEPENDS+=	swig3.0:devel/swig30 \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
USES+=		python
USE_PYTHON=	py3kplist flavors
CONFIGURE_ENV+=	SWIG=${LOCALBASE}/bin/swig3.0
PLIST_SUB+=	VERSION=${PORTVERSION}
.    if ${FLAVOR:Upy27:Mpy2*}
CONFIGURE_ARGS+=--enable-languages="python2"
.    else
CONFIGURE_ARGS+=--enable-languages="python3"
.    endif
.  endif
.endif

post-patch:
.if defined(SLAVEPORT)
	@${FIND} ${BUILD_WRKSRC} -name "Makefile.in" -type f | ${XARGS} \
	${REINPLACE_CMD} -e 's|../../../src/libgpgme.la|-lgpgme|g'
.  if ${SLAVEPORT} == "qt5"
	@${FIND} ${BUILD_WRKSRC} -name "Makefile.in" -type f | ${XARGS} \
	${REINPLACE_CMD} -e 's|../../cpp/src/libgpgmepp.la|-lgpgmepp|g'
.  endif
.endif
	@${REINPLACE_CMD} -e 's|^clfilesdir.*|clfilesdir=$$\(libdir\)/common-lisp/gpgme|g' \
		${WRKSRC}/lang/cl/Makefile.in

post-patch-DOXYGEN-off:
	@${REINPLACE_CMD} -e '/SUBDIRS/s|doc||' \
		${WRKSRC}/lang/qt/Makefile.in

post-patch-TEST-off:
	@${REINPLACE_CMD} -e '/SUBDIRS/s|tests||' \
		${WRKSRC}/lang/python/Makefile.in \
		${WRKSRC}/lang/qt/Makefile.in

# The gnupg programs will create sockets for the tests in a temporary directory
# under /var/run/user/${UID} if it exists. Otherwise, they will try to create
# them in the test build directories. To prevent errors in cases where the test
# build directory path length exceeds the socket path length limitation of 104
# characters, the sockets are redirected to a temporary directory.
pre-build-TEST-on:
	@if [ ! -d "/var/run/user/${UID}" ]; then \
		SOCKETS="dirmngr gpg-agent gpg-agent.browser gpg-agent.extra gpg-agent.ssh scdaemon uiserver"; \
		TESTSUBDIRS="lang/python/tests lang/qt/tests tests/gpg tests/gpgsm"; \
		TMPSOCKETDIR=$$(${MKTEMP} -d -t gpgmetest); \
		${ECHO_CMD} "$${TMPSOCKETDIR}" > ${WRKDIR}/.tmpsocketdir; \
		trap "${RM} -r $${TMPSOCKETDIR}; exit 1" 1 2 3 5 10 13 15; \
			for sock in $${SOCKETS}; do \
				for subdir in $${TESTSUBDIRS}; do \
					${PRINTF} "%%Assuan%%\nsocket=$${TMPSOCKETDIR}/S.$${sock}\n" > ${WRKSRC}/$${subdir}/S.$${sock}; \
				done; \
		  	done; \
	fi

post-build-TEST-on:
	@if [ -f "${WRKDIR}/.tmpsocketdir" ]; then \
		${XARGS} ${RM} -rf < ${WRKDIR}/.tmpsocketdir; \
		${RM} ${WRKDIR}/.tmpsocketdir; \
	fi

pre-test: pre-build-TEST-on

post-test: post-build-TEST-on

.if !defined(SLAVEPORT)
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	cd ${WRKSRC}/lang/qt/doc/generated/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
