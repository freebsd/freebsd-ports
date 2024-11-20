PORTNAME=	sexp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	textproc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	S-expressions processing command-line utility
WWW=		https://github.com/janestreet/sexp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		ocaml-compiler-libs>=0:devel/ocaml-compiler-libs

USES=		gmake ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
GH_TUPLE=	inhabitedtype:angstrom:0.16.1:angstrom \
		janestreet:async:v0.16.0:async \
		janestreet:async_kernel:v0.16.0:async_kernel \
		janestreet:async_rpc_kernel:v0.16.0:async_rpc_kernel \
		janestreet:async_unix:v0.16.0:async_unix \
		janestreet:base:v0.16.3:base \
		janestreet:base_bigstring:v0.16.0:base_bigstring \
		janestreet:base_quickcheck:v0.16.0:base_quickcheck \
		inhabitedtype:bigstringaf:0.10.0:bigstringaf \
		janestreet:bin_prot:v0.16.0:bin_prot \
		janestreet:core:v0.16.2:core \
		janestreet:core_kernel:v0.16.0:core_kernel \
		janestreet:core_unix:v0.16.0:core_unix \
		janestreet:csvfields:v0.16.0:csvfields \
		inhabitedtype:faraday:0.8.2:faraday \
		janestreet:fieldslib:v0.16.0:fieldslib \
		janestreet:int_repr:v0.16.0:int_repr \
		janestreet:jane-street-headers:v0.16.0:jane_street_headers \
		janestreet:jane_rope:v0.16.0:jane_rope \
		janestreet:jsonaf:v0.16.0:jsonaf \
		janestreet:jst-config:v0.16.0:jst_config \
		mirage:ocaml-cstruct:v6.2.0:ocaml_cstruct \
		ocaml:ocaml-re:1.11.0-351-g140deeb:ocaml_re \
		janestreet:ocaml_intrinsics:v0.16.1:ocaml_intrinsics \
		janestreet:parsexp:14af9ab942251783de6abb20e0d0e0eec6080062:parsexp \
		janestreet:ppx_assert:b6e114b0a6ba8bf4fbfec005f06ed529530af3cf:ppx_assert \
		janestreet:ppx_base:v0.16.0:ppx_base \
		janestreet:ppx_bench:v0.16.0:ppx_bench \
		janestreet:ppx_bin_prot:v0.16.0:ppx_bin_prot \
		janestreet:ppx_cold:v0.16.0:ppx_cold \
		janestreet:ppx_compare:399a908f452dd0d4124e82fea686d8f35c2a3d2a:ppx_compare \
		janestreet:ppx_custom_printf:v0.16.0:ppx_custom_printf \
		ocaml-ppx:ppx_derivers:1.2.1:ppx_derivers \
		janestreet:ppx_diff:eebb67b723e9159e36f8d4f6aa52e3d0a569f84f:ppx_diff \
		janestreet:ppx_disable_unused_warnings:1fd5b921db5b14a9209a999ab6bf7dcdaef45e85:ppx_disable_unused_warnings \
		janestreet:ppx_enumerate:v0.16.0:ppx_enumerate \
		janestreet:ppx_expect:936804bbdeecfda5ae2c103da7399ba178639929:ppx_expect \
		janestreet:ppx_fields_conv:v0.16.0:ppx_fields_conv \
		janestreet:ppx_fixed_literal:v0.16.0:ppx_fixed_literal \
		janestreet:ppx_globalize:v0.16.0:ppx_globalize \
		janestreet:ppx_hash:v0.16.0:ppx_hash \
		janestreet:ppx_here:v0.16.0:ppx_here \
		janestreet:ppx_ignore_instrumentation:v0.16.0:ppx_ignore_instrumentation \
		janestreet:ppx_inline_test:v0.17.0:ppx_inline_test \
		janestreet:ppx_jane:v0.16.0:ppx_jane \
		janestreet:ppx_let:v0.16.0:ppx_let \
		janestreet:ppx_log:v0.16.0:ppx_log \
		janestreet:ppx_module_timer:v0.16.0:ppx_module_timer \
		janestreet:ppx_optcomp:v0.16.0:ppx_optcomp \
		janestreet:ppx_optional:v0.16.0:ppx_optional \
		janestreet:ppx_pipebang:v0.16.0:ppx_pipebang \
		janestreet:ppx_sexp_conv:v0.16.0:ppx_sexp_conv \
		janestreet:ppx_sexp_message:v0.16.0:ppx_sexp_message \
		janestreet:ppx_sexp_value:v0.16.0:ppx_sexp_value \
		janestreet:ppx_stable:ee8c759a847f21c3ee600e8da3f8a705d18c45b4:ppx_stable \
		janestreet:ppx_stable_witness:v0.16.0:ppx_stable_witness \
		janestreet:ppx_string:v0.16.0:ppx_string \
		janestreet:ppx_tydi:v0.16.0:ppx_tydi \
		janestreet:ppx_typerep_conv:v0.16.0:ppx_typerep_conv \
		janestreet:ppx_variants_conv:v0.16.0:ppx_variants_conv \
		janestreet:ppxlib:8a0cb7122d7d454c20d732621795d910018d1b66:ppxlib \
		janestreet:ppxlib_jane:33fc3e4bd54ea4e3292d4d32936a46349c043fec:ppxlib_jane \
		janestreet:protocol_version_header:v0.16.0:protocol_version_header \
		janestreet:re2:v0.17.0:re2 \
		janestreet:regex_parser_intf:v0.16.0:regex_parser_intf \
		janestreet:sexp_diff:v0.16.0:sexp_diff \
		janestreet:sexp_macro:v0.16.0:sexp_macro \
		janestreet:sexp_pretty:v0.16.0:sexp_pretty \
		janestreet:sexp_select:v0.17.0:sexp_select \
		janestreet:sexplib:aca60491fec3b7aafd0d4f29957bf34fc0f936ba:sexplib \
		janestreet:sexplib0:v0.16.0:sexplib0 \
		janestreet:shell:v0.16.0:shell \
		janestreet:spawn:v0.17.0:spawn \
		janestreet:splittable_random:v0.17.0:splittable_random \
		janestreet:stdio:v0.16.0:stdio \
		janestreet:time_now:v0.17.0:time_now \
		janestreet:timezone:v0.16.0:timezone \
		janestreet:typerep:v0.16.0:typerep \
		janestreet:uopt:v0.17.0:uopt \
		janestreet:variantslib:v0.16.0:variantslib
USE_OCAML=	yes
DUNE_ARGS=	bin/main.exe

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	change_by_example.md change_semantics.md \
		query_by_example.md query_semantics.md \

OPTIONS_DEFINE=		DOCS FZF
FZF_DESC=		Run-time dependency on fzf
FZF_RUN_DEPENDS=	${LOCALBASE}/bin/fzf:textproc/fzf

post-extract:
	@${MKDIR} ${PATCH_WRKSRC}/vendor
.for _tuple in ${GH_TUPLE}
	@${MV} ${WRKSRC_${_tuple:C/.*://}} ${PATCH_WRKSRC}/vendor
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_build/default/bin/main.exe \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/change_by_example.md \
		${WRKSRC}/doc/change_semantics.md \
		${WRKSRC}/doc/query_by_example.md \
		${WRKSRC}/doc/query_semantics.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
