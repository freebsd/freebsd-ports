PORTNAME=	gemserv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	https://git.sr.ht/~int80h/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ea@uoga.net
COMMENT=	Gemini server written in Rust

LICENSE=	APACHE20 BSD3CLAUSE MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_RC_SUBR=	gemserv

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bytes-0.5.6 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		colored-1.9.3 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.0.0 \
		futures-core-0.3.8 \
		futures-macro-0.3.8 \
		futures-task-0.3.8 \
		futures-util-0.3.8 \
		idna-0.2.0 \
		iovec-0.1.4 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.4 \
		mime-0.3.16 \
		mime_guess-2.0.3 \
		mio-0.6.23 \
		mio-uds-0.6.8 \
		net2-0.2.37 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		once_cell-1.5.2 \
		openssl-0.10.32 \
		percent-encoding-2.1.0 \
		pin-project-1.0.2 \
		pin-project-internal-1.0.2 \
		pin-project-lite-0.1.11 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		proc-macro-hack-0.5.19 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		serde-1.0.118 \
		serde_derive-1.0.118 \
		signal-hook-registry-1.3.0 \
		simple_logger-1.11.0 \
		slab-0.4.2 \
		syn-1.0.55 \
		time-0.1.44 \
		tinyvec-1.1.0 \
		tinyvec_macros-0.1.0 \
		tokio-0.2.24 \
		tokio-openssl-0.4.0 \
		toml-0.5.8 \
		unicase-2.6.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.16 \
		unicode-xid-0.2.1 \
		url-2.2.0 \
		version_check-0.9.2 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		mio-named-pipes-0.1.7 \
		openssl-sys-0.9.61 \
		hermit-abi-0.1.18 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		kernel32-sys-0.2.2 \
		miow-0.2.2 \
		miow-0.3.7 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-build-0.1.1 \
		ws2_32-sys-0.2.1 \
		vcpkg-0.2.12
CARGO_FEATURES=

SUB_FILES=	config.toml.sample index.gmi.sample
SUB_LIST=	GEMSERV_GROUP=${GEMSERV_GROUP} \
		GEMSERV_USER=${GEMSERV_USER}

USERS=		${GEMSERV_USER}
GROUPS=		${GEMSERV_GROUP}

PLIST_SUB=	GEMSERV_DATADIR=${PREFIX}/gemini/gemserv-dist

OPTIONS_DEFINE=	STATICONLY
OPTIONS_DEFAULT=

STATICONLY_DESC=	Only serve static files, no additional features (CGI..)
STATICONLY_VARS=	CARGO_FEATURES+=--no-default-features

GEMSERV_GROUP?=	gemserv
GEMSERV_USER?=	gemserv

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.toml ${STAGEDIR}${ETCDIR}/config.toml-dist
	${INSTALL_DATA} ${WRKDIR}/config.toml.sample ${STAGEDIR}${ETCDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${WRKSRC}/UPDATING ${STAGEDIR}${DOCSDIR}

	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/cgi-scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

	${MKDIR} ${STAGEDIR}${PREFIX}/gemini/gemserv-dist
	${INSTALL_DATA} ${WRKDIR}/index.gmi.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
