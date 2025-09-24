PORTNAME=	gpgme
PORTVERSION=	2.0.1
CATEGORIES?=	security
MASTER_SITES=	GNUPG/gpgme

MAINTAINER=	jhale@FreeBSD.org
COMMENT?=	Library to make access to GnuPG easier
WWW=		https://www.gnupg.org/related_software/gpgme/

LICENSE?=	LGPL21+
LICENSE_FILE?=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error

USES=		compiler:c11 cpe gmake libtool localbase:ldflags pathfix tar:bzip2
USE_LDCONFIG=	yes
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-languages="cl"
CFLAGS+=	-Wno-suggest-override -Wno-unknown-warning-option
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

INFO=		gpgme
PORTDOCS=	AUTHORS INSTALL NEWS README

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

post-patch:
	@${REINPLACE_CMD} -e 's|^clfilesdir.*|clfilesdir=$$\(libdir\)/common-lisp/gpgme|g' \
		${WRKSRC}/lang/cl/Makefile.in

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
