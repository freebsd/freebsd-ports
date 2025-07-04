PORTNAME=	adblock
DISTVERSION=	0.6.0
PORTREVISION=	36
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vendion@gmail.com
COMMENT=	Brave's adblock library in Python
WWW=		https://pypi.org/project/adblock/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

# Although the port builds fine on some 32-bit architectures (e.g. i386) it
# doesn't support creating 32-bit Python wheels for FreeBSD.  Thus save build
# time and skip the port at a early stage.
# SEE devel/py-maturin/Makefile
NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc
NOT_FOR_ARCHS_REASON=	the creation of 32-bit Python wheels is not supported for FreeBSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=0.8.3:devel/py-maturin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=20.2.3:devel/py-pip@${PY_FLAVOR} \
		public_suffix_list>0:dns/public_suffix_list

USES=		cargo python

USE_GITHUB=	yes
GH_ACCOUNT=	ArniDagur
GH_PROJECT=	python-adblock
USE_PYTHON=	autoplist concurrent cython distutils

CARGO_CRATES=	adblock-0.5.6 \
		addr-0.14.0 \
		adler-1.0.2 \
		aho-corasick-0.7.18 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		byteorder-1.4.3 \
		cfg-if-1.0.0 \
		crc32fast-1.3.2 \
		either-1.7.0 \
		flate2-1.0.24 \
		form_urlencoded-1.0.1 \
		idna-0.2.3 \
		indoc-1.0.6 \
		itertools-0.10.3 \
		libc-0.2.126 \
		lock_api-0.4.7 \
		matches-0.1.9 \
		memchr-2.5.0 \
		miniz_oxide-0.5.3 \
		num-traits-0.2.15 \
		once_cell-1.13.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.3 \
		paste-1.0.7 \
		percent-encoding-2.1.0 \
		proc-macro2-1.0.40 \
		psl-2.0.90 \
		psl-types-2.0.10 \
		pyo3-0.16.5 \
		pyo3-build-config-0.16.5 \
		pyo3-ffi-0.16.5 \
		pyo3-macros-0.16.5 \
		pyo3-macros-backend-0.16.5 \
		quote-1.0.20 \
		redox_syscall-0.2.13 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		rmp-0.8.11 \
		rmp-serde-0.13.7 \
		rmp-serde-0.15.5 \
		scopeguard-1.1.0 \
		seahash-3.0.7 \
		serde-1.0.139 \
		serde_derive-1.0.139 \
		smallvec-1.9.0 \
		syn-1.0.98 \
		target-lexicon-0.12.4 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.0 \
		twoway-0.2.2 \
		unchecked-index-0.2.2 \
		unicode-bidi-0.3.8 \
		unicode-ident-1.0.2 \
		unicode-normalization-0.1.21 \
		unindent-0.1.9 \
		url-2.2.2 \
		windows-sys-0.36.1 \
		windows_aarch64_msvc-0.36.1 \
		windows_i686_gnu-0.36.1 \
		windows_i686_msvc-0.36.1 \
		windows_x86_64_gnu-0.36.1 \
		windows_x86_64_msvc-0.36.1
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

CONFLICTS_INSTALL=	py3[0-9]-adblock py3[0-9][0-9]-adblock # lib/libadblock.so

# Required since maturin >= 0.13.0
BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

# This is to prevent Mk/Uses/python.mk do-configure target from firing.
do-configure:

do-build:
	@(cd ${BUILD_WRKSRC} ; \
		PSL_PATH="${PREFIX}/share/public_suffix_list/public_suffix_list.dat" \
		${SETENV} ${MAKE_ENV} maturin-${PYTHON_VER} build --release \
		${WITH_DEBUG:D:U--strip})

# Due to upstream not supplying a setup.py file or other way to install
# using pip command for now...
do-install:
	@(cd ${INSTALL_WRKSRC} ; \
		${INSTALL_DATA} "target/release/libadblock.so" \
		"${STAGEDIR}/${PREFIX}/lib" ; \
		${SETENV} ${MAKE_ENV} pip-${PYTHON_VER} install --isolated \
		--root=${STAGEDIR} --ignore-installed --no-deps target/wheels/*.whl)

post-install:
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${PREFIX} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
# Regenerate .PLIST.pymodtemp to get all installed files from
# ${STAGEDIR} because the file that is generated in the first place
# contains only the EGG files as a whole.
# SEE devel/py-maturin/Makefile
	@${FIND} ${STAGEDIR} \
		-type \
		f \
		-o \
		-type \
		l | \
		${SORT} | \
		${SED} -e 's|${STAGEDIR}||' \
		> \
		${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
