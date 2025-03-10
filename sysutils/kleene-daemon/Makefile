PORTNAME=	kleene-daemon
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
DISTVERSIONSUFFIX=	-rc.5
CATEGORIES=	sysutils
MASTER_SITES+=	https://builds.hex.pm/installs/1.16.0/:hex
DISTFILES+=	hex-${_HEXPM_VERSION}.ez:hex

MAINTAINER=	lasse@philomath.dk
COMMENT=	Kleene backend daemon for managing containers on FreeBSD
WWW=		https://kleene.dev

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		mix:lang/elixir \
		rebar3:devel/rebar3

USES=		gmake ssl
USE_GITHUB=	yes

GH_ACCOUNT=	kleene-project
GH_PROJECT=	kleened
USE_RC_SUBR=	kleened

MAKE_ENV+=	ERL_LIBS='' \
		HEX_HOME=${WRKDIR}/.hex \
		HEX_OFFLINE=true \
		LANG=en_US_UTF-8 \
		LC_ALL=en_US.UTF-8 \
		MIX_ARCHIVES=${WRKDIR} \
		MIX_ENV=prod \
		MIX_HOME=${WRKDIR}/.mix \
		MIX_PATH=${WRKDIR}/.mix/archives/hex-${_HEXPM_VERSION}/hex-${_HEXPM_VERSION}/ebin \
		MIX_REBAR3=${LOCALBASE}/bin/rebar3

ETCDIR=		${PREFIX}/etc/kleened
SUB_FILES=	pkg-message
PLIST_SUB=	DISTVERSION=${DISTVERSION}

_HEXPM_VERSION=		2.1.1
_HEX_DIR=		${WRKDIR}/.mix/archives/hex-${_HEXPM_VERSION}
_RELEASE_PATH=		${WRKSRC}/_build/prod/rel/kleened
_RELEASE_BINARIES=	escript dialyzer erlexec beam.smp heart dyn_erl to_erl \
			erlc epmd run_erl typer inet_gethost erl_child_setup \
			ct_run erl_call yielding_c_fun

.include <bsd.port.pre.mk>

post-extract:
	${MKDIR} ${_HEX_DIR}
	${MV} ${WRKDIR}/hex-* \
		${_HEX_DIR}/

do-build:
	(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/mix do deps.compile, \
		compile, release)

do-install:
# sample configs
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/example/kleened_config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample
	${INSTALL_DATA} ${WRKSRC}/example/pf.conf.kleene \
		${STAGEDIR}${ETCDIR}/pf.conf.kleene.sample
# the release
	${CP} -a ${WRKSRC}/_build/prod/rel/kleened ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/priv/bin/kleened_pty \
		${STAGEDIR}${PREFIX}/libexec/kleened/bin/
	${RM} ${STAGEDIR}${PREFIX}/libexec/kleened/bin/*.src
# strip binaries and objects
	${FIND} ${STAGEDIR}${PREFIX}/libexec/kleened/lib -type f -name \
		*.so -exec ${STRIP_CMD} {} \;
.for bin in ${_RELEASE_BINARIES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/kleened/erts-*/bin/${bin}
.endfor

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} libexec/kleened/erts-* -type f -o -type l | \
		${SORT} >> ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} libexec/kleened/lib/* -type f -o -type l | \
		${SORT} >> ${TMPPLIST}

.include <bsd.port.post.mk>
