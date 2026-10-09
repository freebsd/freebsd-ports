PORTNAME=	patdiff
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1
CATEGORIES=	textproc

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Colored patience diffs for the discerning developer
WWW=		https://github.com/janestreet/patdiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash \
		${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_compare/META:devel/ocaml-ppx_compare \
		${SA_DIR}/ppx_hash/META:devel/ocaml-ppx_hash \
		${SA_DIR}/ppx_optcomp/META:devel/ocaml-ppx_optcomp \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/re/META:devel/ocaml-re \
		${SA_DIR}/sexplib/META:devel/ocaml-sexplib \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0 \
		${SA_DIR}/stdio/META:devel/ocaml-stdio

USES=		ocaml:build,dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
# Jane Street libraries not (yet) in the ports tree are vendored
GH_TUPLE=	\
		janestreet:base_bigstring:v0.16.0:base_bigstring/vendor/base_bigstring \
		janestreet:base_quickcheck:v0.16.0:base_quickcheck/vendor/base_quickcheck \
		janestreet:bin_prot:v0.16.0:bin_prot/vendor/bin_prot \
		janestreet:core:v0.16.2:core/vendor/core \
		janestreet:core_kernel:v0.16.0:core_kernel/vendor/core_kernel \
		janestreet:core_unix:v0.16.0:core_unix/vendor/core_unix \
		janestreet:expect_test_helpers_core:v0.16.0:expect_test_helpers_core/vendor/expect_test_helpers_core \
		janestreet:fieldslib:v0.16.0:fieldslib/vendor/fieldslib \
		janestreet:int_repr:v0.16.0:int_repr/vendor/int_repr \
		janestreet:jane-street-headers:v0.16.0:jane_street_headers/vendor/jane-street-headers \
		janestreet:jst-config:v0.16.0:jst_config/vendor/jst-config \
		janestreet:ocaml_intrinsics:v0.16.2:ocaml_intrinsics/vendor/ocaml_intrinsics \
		janestreet:patience_diff:v0.16.0:patience_diff/vendor/patience_diff \
		janestreet:ppx_assert:v0.16.0:ppx_assert/vendor/ppx_assert \
		janestreet:ppx_base:v0.16.0:ppx_base/vendor/ppx_base \
		janestreet:ppx_bench:v0.16.0:ppx_bench/vendor/ppx_bench \
		janestreet:ppx_bin_prot:v0.16.0:ppx_bin_prot/vendor/ppx_bin_prot \
		janestreet:ppx_cold:v0.16.0:ppx_cold/vendor/ppx_cold \
		janestreet:ppx_custom_printf:v0.16.0:ppx_custom_printf/vendor/ppx_custom_printf \
		janestreet:ppx_disable_unused_warnings:v0.16.0:ppx_disable_unused_warnings/vendor/ppx_disable_unused_warnings \
		janestreet:ppx_enumerate:v0.16.0:ppx_enumerate/vendor/ppx_enumerate \
		janestreet:ppx_expect:v0.16.2:ppx_expect/vendor/ppx_expect \
		janestreet:ppx_fields_conv:v0.16.0:ppx_fields_conv/vendor/ppx_fields_conv \
		janestreet:ppx_fixed_literal:v0.16.0:ppx_fixed_literal/vendor/ppx_fixed_literal \
		janestreet:ppx_globalize:v0.16.0:ppx_globalize/vendor/ppx_globalize \
		janestreet:ppx_here:v0.16.0:ppx_here/vendor/ppx_here \
		janestreet:ppx_ignore_instrumentation:v0.16.0:ppx_ignore_instrumentation/vendor/ppx_ignore_instrumentation \
		janestreet:ppx_inline_test:v0.16.0:ppx_inline_test/vendor/ppx_inline_test \
		janestreet:ppx_jane:v0.16.0:ppx_jane/vendor/ppx_jane \
		janestreet:ppx_let:v0.16.0:ppx_let/vendor/ppx_let \
		janestreet:ppx_log:v0.16.0:ppx_log/vendor/ppx_log \
		janestreet:ppx_module_timer:v0.16.0:ppx_module_timer/vendor/ppx_module_timer \
		janestreet:ppx_optional:v0.16.0:ppx_optional/vendor/ppx_optional \
		janestreet:ppx_pipebang:v0.16.0:ppx_pipebang/vendor/ppx_pipebang \
		janestreet:ppx_sexp_message:v0.16.0:ppx_sexp_message/vendor/ppx_sexp_message \
		janestreet:ppx_sexp_value:v0.16.0:ppx_sexp_value/vendor/ppx_sexp_value \
		janestreet:ppx_stable:v0.16.0:ppx_stable/vendor/ppx_stable \
		janestreet:ppx_stable_witness:v0.16.0:ppx_stable_witness/vendor/ppx_stable_witness \
		janestreet:ppx_string:v0.16.0:ppx_string/vendor/ppx_string \
		janestreet:ppx_tydi:v0.16.0:ppx_tydi/vendor/ppx_tydi \
		janestreet:ppx_typerep_conv:v0.16.0:ppx_typerep_conv/vendor/ppx_typerep_conv \
		janestreet:ppx_variants_conv:v0.16.0:ppx_variants_conv/vendor/ppx_variants_conv \
		janestreet:sexp_pretty:v0.16.0:sexp_pretty/vendor/sexp_pretty \
		janestreet:spawn:v0.15.1:spawn/vendor/spawn \
		janestreet:splittable_random:v0.16.0:splittable_random/vendor/splittable_random \
		janestreet:time_now:v0.16.0:time_now/vendor/time_now \
		janestreet:timezone:v0.16.0:timezone/vendor/timezone \
		janestreet:typerep:v0.16.0:typerep/vendor/typerep \
		janestreet:variantslib:v0.16.0:variantslib/vendor/variantslib

DUNE_INSTALL_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/share/man \
			--destdir=${STAGEDIR} --sections=bin,man
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

PLIST_FILES=	bin/patdiff \
		bin/patdiff-git-wrapper \
		share/man/man1/patdiff.1.gz

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
# vendored_dirs needs dune lang >= 1.11
	@${REINPLACE_CMD} -e 's/(lang dune 1.10)/(lang dune 1.11)/' \
		${WRKSRC}/dune-project
	@${ECHO_CMD} '(vendored_dirs *)' > ${WRKSRC}/vendor/dune
# fix the missing version string
	@${REINPLACE_CMD} -e 's|Command_unix.run Compare.command|Command_unix.run \
		~version:"${DISTVERSION}" Compare.command|' ${WRKSRC}/bin/main.ml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/patdiff

.include <bsd.port.mk>
