# Created by: teramoto@comm.eng.osaka-u.ac.jp
# $FreeBSD$

PORTNAME=	gpgme
PORTVERSION=	1.10.0
PORTREVISION?=	1
CATEGORIES?=	security
MASTER_SITES=	GNUPG/gpgme

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Library to make access to GnuPG easier

LICENSE?=	LGPL21+
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error

GNU_CONFIGURE=	yes
USES=		cpe gmake libtool localbase:ldflags tar:bzip2
USE_LDCONFIG=	yes

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

# Tests may fail if the test directory path length surpasses the socket path
# length limitation of 104 characters. Due to the way gnupg creates sockets,
# the easiest way to overcome this is to create a /var/run/user/${UID}
# directory set with 700 permissions and owned by the effective user building
# the port.
TEST_CONFIGURE_ENABLE=	g13-test gpg-test gpgconf-test gpgsm-test
TEST_PREVENTS=		GNUPG1
TEST_PREVENTS_MSG=	TEST option is mainly designed for use with the GNUPG2 option

UISERVER_DESC=			GnuPG UI server support
UISERVER_CONFIGURE_ENABLE=	fd-passing
.endif

.include <bsd.port.options.mk>

.if defined(SLAVEPORT)
LIB_DEPENDS+=	libgpgme.so:security/gpgme
BUILD_WRKSRC=	${WRKSRC}/lang/${BINDING_NAME}
INSTALL_WRKSRC=	${WRKSRC}/lang/${BINDING_NAME}
NO_TEST=	yes

.  if ${SLAVEPORT} == "cpp"
CONFIGURE_ARGS+=--enable-languages="cpp"
USES+=		compiler:c++11-lib
# Unhide std::to_string() to fix build with GCC 4.8 (ports/193528).
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.  endif

.  if ${SLAVEPORT} == "qt5"
LIB_DEPENDS+=	libgpgmepp.so:security/gpgme-cpp
CONFIGURE_ARGS+=--enable-languages="cpp qt"
USES+=		compiler:c++11-lib pkgconfig
USE_QT5=	buildtools_build core testlib
.  endif

.  if ${SLAVEPORT} == "python"
BUILD_DEPENDS+=	swig3.0:devel/swig30 \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${FLAVOR}
USES+=		python
USE_PYTHON=	py3kplist flavors
CONFIGURE_ENV+=	SWIG=${LOCALBASE}/bin/swig3.0
PLIST_SUB+=	VERSION=${PORTVERSION}
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
	@${REINPLACE_CMD} -e '/SUBDIRS/s|tests||' \
		${WRKSRC}/lang/python/Makefile.in \
		${WRKSRC}/lang/qt/Makefile.in

.if !defined(SLAVEPORT)
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
