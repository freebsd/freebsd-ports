.if !defined(_SCCACHE_OVERLAY_INCLUDED) && !defined(NO_SCCACHE)
_SCCACHE_OVERLAY_INCLUDED=	yes

SCCACHE_SIZE?=		16G
SCCACHE_UNIX_LISTEN?=	/tmp/sccache-overlay.socket

_SCCACHE_LIBS=	${LOCALBASE}/share/sccache/overlay/lib
.for odir in ${OVERLAYS}
.  if exists(${odir}/bin/sccache)
SCCACHE_BIN?=	${odir}/bin/sccache
_SCCACHE_LIBS=	${odir}/lib
.  endif
.endfor
SCCACHE_BIN?=	${LOCALBASE}/share/sccache/overlay/bin/sccache
.if !exists(${SCCACHE_BIN})
IGNORE=		could not find sccache: ${SCCACHE_BIN}
.endif

.if defined(CCACHE_DIR)
SCCACHE_DIR?=	${CCACHE_DIR}/sccache
.endif
.if !defined(SCCACHE_DIR)
IGNORE=		SCCACHE_DIR not set
.endif

_SCCACHE_ENV=	RUSTC_WRAPPER="${SCCACHE_BIN}" \
		SCCACHE_CACHE_SIZE="${SCCACHE_SIZE}" \
		SCCACHE_DIR="${SCCACHE_DIR}" \
		SCCACHE_MAX_FRAME_LENGTH=104857600 \
		SCCACHE_UNIX_LISTEN="${SCCACHE_UNIX_LISTEN}"
CONFIGURE_ENV+=	${_SCCACHE_ENV}
MAKE_ENV+=	${_SCCACHE_ENV}

_USES_configure+=	250:sccache-start
_USES_stage+=		950:sccache-stats

sccache-start:
	@${ECHO_MSG} "==> Starting sccache"
	@${LN} -Fs ${_SCCACHE_LIBS} /tmp/sccache-overlay
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --start-server || ${TRUE}
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --show-stats

sccache-stats:
	@${ECHO_MSG} "==> sccache statistics"
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --show-stats || ${TRUE}

# We let Poudriere clean up the server. Users who build locally
# can stop the server with `make sccache-stop` manually or wait
# 10 minutes after the build until it shuts down automatically.
sccache-stop:
	@${ECHO_MSG} "==> Stopping sccache"
	@${SETENV} ${_SCCACHE_ENV} ${SCCACHE_BIN} --stop-server

.endif
