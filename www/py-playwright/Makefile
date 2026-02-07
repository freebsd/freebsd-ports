PORTNAME=	playwright
DISTVERSIONPREFIX=	v
DISTVERSION=	1.55.0
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tarball
MASTER_SITES+=	https://playwright.azureedge.net/builds/driver/next/:driver # zip archive with JS scripts called "driver" are bundled with the Python module
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	playwright-${DISTVERSION}-beta-1756314050000-linux.zip:driver
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} # do not extract the JS scripts archive

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-level API to automate web browsers
WWW=		https://playwright.dev/python/ \
		https://github.com/Microsoft/playwright-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.45.1:devel/py-wheel@${PY_FLAVOR} \
		curl:ftp/curl
LINUX_DEPENDS=	linux-${LINUX_BASE}-alsa-lib>0:audio/linux-${LINUX_BASE}-alsa-lib \
		linux-${LINUX_BASE}-at-spi2-atk>0:accessibility/linux-${LINUX_BASE}-at-spi2-atk \
		linux-${LINUX_BASE}-atk>0:accessibility/linux-${LINUX_BASE}-atk \
		linux-${LINUX_BASE}-cairo>0:graphics/linux-${LINUX_BASE}-cairo \
		linux-${LINUX_BASE}-cups-libs>0:print/linux-${LINUX_BASE}-cups-libs \
		linux-${LINUX_BASE}-dbus-libs>0:devel/linux-${LINUX_BASE}-dbus-libs \
		linux-${LINUX_BASE}-dri>0:graphics/linux-${LINUX_BASE}-dri \
		linux-${LINUX_BASE}-gstreamer1>0:multimedia/linux-${LINUX_BASE}-gstreamer1 \
		linux-${LINUX_BASE}-libxkbcommon>0:x11/linux-${LINUX_BASE}-libxkbcommon \
		linux-${LINUX_BASE}-nspr>0:devel/linux-${LINUX_BASE}-nspr \
		linux-${LINUX_BASE}-nss>0:security/linux-${LINUX_BASE}-nss \
		linux-${LINUX_BASE}-pango>0:x11-toolkits/linux-${LINUX_BASE}-pango
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}greenlet>=3.1.1:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyee>=13:devel/py-pyee@${PY_FLAVOR}
RUN_DEPENDS+=	node24>0:www/node24 \
		${LINUX_DEPENDS}

USES=		linux:rl9 python
USE_PYTHON=	pep517 concurrent autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Microsoft
GH_PROJECT=	playwright-python

LINUX_BASE=	${linux_ARGS}

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${PORTVERSION}

XARCH:=		${ARCH:S/amd64/x64/}

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-patch: # replace URL in JS scripts with DISTDIR
	@${REINPLACE_CMD} \
		-e 's|url = "https://playwright.azureedge.net/builds/driver/"|url = "file://${DISTDIR}/"|' \
		${WRKSRC}/setup.py

post-install:
	# replace node binary from the zip archive with JS scripts with the FreeBSD native binary
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playwright/driver && \
		${RM} node && \
		${LN} -s ${LOCALBASE}/bin/node
	# patch JS scripts: process.platform
	@${GREP} -rl 'process.platform === "linux"' ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} | \
		${GREP} "\.js$$" | \
		${XARGS} ${REINPLACE_CMD} -i '' \
			-e 's/process.platform === "linux"/(process.platform === "linux" || process.platform === "freebsd")/'
	@${GREP} -rl 'process.platform !== "linux"' ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} | \
		${GREP} "\.js$$" | \
		${XARGS} ${REINPLACE_CMD} -i '' \
			-e 's/process.platform !== "linux"/(process.platform !== "linux" \&\& process.platform !== "freebsd")/'
	# patch JS scripts: env var PLAYWRIGHT_HOST_PLATFORM_OVERRIDE
	@${REINPLACE_CMD} \
		-i '' -e 's/if (process.env.PLAYWRIGHT_HOST_PLATFORM_OVERRIDE) {/if (true) {/' \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playwright/driver/package/lib/server/utils/hostPlatform.js
	@${REINPLACE_CMD} \
		-i '' -e 's/process.env.PLAYWRIGHT_HOST_PLATFORM_OVERRIDE/"ubuntu24.04-${XARCH}"/' \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/playwright/driver/package/lib/server/utils/hostPlatform.js

do-test:
	@${SETENV} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/playwright install
.for test in test-sync.py test-async.py
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/${test}
.endfor

.include <bsd.port.mk>
