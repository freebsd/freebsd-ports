PORTNAME=	paseo-relay
DISTVERSION=	g20261125
CATEGORIES=	net
MASTER_SITES=	https://repo.hex.pm/tarballs/:hexpm \
		https://builds.hex.pm/installs/1.20.0/:hex
DISTFILES=	${HEX_PACKAGES:S/$/.tar:hexpm/} \
		hex-${_HEX_VERSION}-otp-${_ERLANG_VER}.ez:hex
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Agentic development environment (relay server)
WWW=		https://github.com/getpaseo/paseo-relay

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	erlang-runtime${_ERLANG_VER}>0:lang/erlang-runtime${_ERLANG_VER} \
		mix:lang/elixir-devel \
		rebar3:devel/rebar3

USES=		ssl

USE_GITHUB=	yes
GH_ACCOUNT=	getpaseo
GH_TAGNAME=	74de39d04985

USE_RC_SUBR=	paseo_relay

USERS=		paseo-relay
GROUPS=		paseo-relay

HEX_PACKAGES=	cowboy-2.21.0 \
		cowlib-2.22.0 \
		dns_cluster-0.2.0 \
		jason-1.4.5 \
		ranch-2.4.0 \
		syn-3.4.2
_HEX_VERSION=	2.7.0
# _ERLANG_VER must match the OTP release lang/elixir-devel is built with.
_ERLANG_VER=	29

SUB_FILES=	pkg-message

MAKE_ENV+=	ERL_LIBS="" \
		HEX_HOME=${WRKDIR}/.hex \
		HEX_OFFLINE=1 \
		LANG=C.UTF-8 \
		MIX_ARCHIVES=${WRKDIR}/.mix/archives \
		MIX_ENV=prod \
		MIX_HOME=${WRKDIR}/.mix \
		MIX_PATH=${_HEX_DIR}/hex-${_HEX_VERSION}/ebin \
		MIX_REBAR3=${LOCALBASE}/bin/rebar3 \
		PATH=${LOCALBASE}/lib/erlang${_ERLANG_VER}/bin:${PATH}

_HEX_DIR=	${WRKDIR}/.mix/archives/hex-${_HEX_VERSION}
_RELEASE_DIR=	${WRKSRC}/_build/prod/rel/paseo_relay
_INSTALL_DIR=	${PREFIX}/libexec/paseo_relay

post-extract:
	@${MKDIR} ${_HEX_DIR}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/hex-${_HEX_VERSION}-otp-${_ERLANG_VER}.ez \
		-C ${_HEX_DIR}

do-build:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/elixir ${FILESDIR}/hex-deps.exs \
		${DISTDIR}/${DIST_SUBDIR} ${HEX_PACKAGES:C/-[^-]*$//}
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mix do deps.compile, compile, release

do-install:
	@${MKDIR} ${STAGEDIR}${_INSTALL_DIR}
	cd ${_RELEASE_DIR} && ${PAX} -rw . ${STAGEDIR}${_INSTALL_DIR}
# The release cookie is generated at build time and would be the same for
# every installation; the rc script passes a fresh RELEASE_COOKIE instead.
	${RM} ${STAGEDIR}${_INSTALL_DIR}/releases/COOKIE \
		${STAGEDIR}${_INSTALL_DIR}/bin/*.bat \
		${STAGEDIR}${_INSTALL_DIR}/erts-*/bin/*.src
	@${FIND} ${STAGEDIR}${_INSTALL_DIR} -type f -exec ${FILE} {} + | \
		${GREP} 'ELF.*FreeBSD' | ${AWK} -F: '{print $$1}' | \
		${XARGS} ${STRIP_CMD}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s ${_INSTALL_DIR:S|^${PREFIX}/||} -not -type d >> ${TMPPLIST}

.include <bsd.port.mk>
