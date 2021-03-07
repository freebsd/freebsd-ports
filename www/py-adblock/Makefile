# $FreeBSD$

PORTNAME=	adblock
DISTVERSION=	0.4.2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vendion@gmail.com
COMMENT=	Brave's adblock library in Python

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

USES=		cargo python:3.6+

USE_GITHUB=	yes
GH_ACCOUNT=	ArniDagur
GH_PROJECT=	python-adblock
USE_PYTHON=	autoplist concurrent cython distutils

CARGO_CRATES=	adblock-0.3.4 \
		addr-0.2.0 \
		addr2line-0.14.0 \
		adler-0.2.3 \
		aho-corasick-0.7.15 \
		autocfg-1.0.1 \
		backtrace-0.3.55 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		core-foundation-0.9.1 \
		core-foundation-sys-0.8.2 \
		crc32fast-1.2.1 \
		ctor-0.1.16 \
		either-1.6.1 \
		error-chain-0.12.4 \
		flate2-1.0.19 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.0 \
		getrandom-0.1.15 \
		ghost-0.1.2 \
		gimli-0.23.0 \
		idna-0.1.5 \
		idna-0.2.0 \
		indoc-1.0.3 \
		instant-0.1.9 \
		inventory-0.1.10 \
		inventory-impl-0.1.10 \
		itertools-0.9.0 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		lock_api-0.4.2 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.4 \
		miniz_oxide-0.4.3 \
		native-tls-0.2.6 \
		num-traits-0.2.14 \
		object-0.22.0 \
		once_cell-1.5.2 \
		openssl-0.10.31 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.59 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.1 \
		paste-1.0.4 \
		percent-encoding-1.0.1 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.24 \
		psl-0.4.1 \
		psl-codegen-0.4.2 \
		psl-lexer-0.2.0 \
		pyo3-0.13.1 \
		pyo3-macros-0.13.1 \
		pyo3-macros-backend-0.13.1 \
		quote-0.6.13 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		remove_dir_all-0.5.3 \
		rental-0.5.5 \
		rental-impl-0.5.5 \
		rmp-0.8.9 \
		rmp-serde-0.13.7 \
		rustc-demangle-0.1.18 \
		rustc_version-0.2.3 \
		schannel-0.1.19 \
		scopeguard-1.1.0 \
		seahash-3.0.7 \
		security-framework-2.0.0 \
		security-framework-sys-2.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		sequence_trie-0.3.6 \
		serde-1.0.118 \
		serde_derive-1.0.118 \
		smallvec-1.5.1 \
		stable_deref_trait-1.2.0 \
		syn-0.14.9 \
		syn-1.0.54 \
		tempfile-3.1.0 \
		thread_local-1.0.1 \
		tinyvec-1.1.0 \
		tinyvec_macros-0.1.0 \
		twoway-0.2.1 \
		unchecked-index-0.2.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.16 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.1 \
		unindent-0.1.7 \
		url-1.7.2 \
		url-2.2.0 \
		vcpkg-0.2.11 \
		version_check-0.9.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

# This is to prevent Mk/Uses/python.mk do-configure target from firing.
do-configure:

do-build:
	@(cd ${BUILD_WRKSRC} ; \
		PSL_PATH=""/usr/local/share/public_suffix_list/public_suffix_list.dat ${SETENV} \
		${MAKE_ENV} maturin build --release ${WITH_DEBUG:D:U--strip})

# Due to upstream not supplying a setup.py file or other way to install
# using pip command for now...
do-install:
	@(cd ${INSTALL_WRKSRC} ; \
		${INSTALL_DATA} "target/release/libadblock.so" \
		"${STAGEDIR}/${PREFIX}/lib" ; \
		${SETENV} ${MAKE_ENV} pip install --isolated --root=${STAGEDIR} \
		--ignore-installed --no-deps target/wheels/*.whl)

post-install:
	(cd ${STAGEDIR}${PREFIX} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${PREFIX} \
		-f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/adblock/adblock*.so
# Regenerate .PLIST.pymodtemp to get all installed files from
# ${STAGEDIR} because the file that is generated in the first place
# contains only the EGG files as a whole.
# SEE devel/py-maturin/Makefile
	@${FIND} ${STAGEDIR} \
		-type f -o -type l | \
		${SORT} | \
		${SED} -e 's|${STAGEDIR}||' \
		> ${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
