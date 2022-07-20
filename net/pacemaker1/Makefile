PORTVERSION=		1.1.24
PORTREVISION=		4
PKGNAMESUFFIX=		1

.include "${.CURDIR}/Makefile.common"

CONFLICTS+=		pacemaker2

SHEBANG_FILES+=		cts/cts \
			cts/lxc_autogen.sh.in \
			fencing/* \
			lrmd/* \
			mcp/* \
			tools/* \
			xml/* \
			BasicSanity.sh \
			coverage.sh.in \
			cts/CTSlab.py \
			pengine/regression.sh

REPLACE_ARGS_GETOPT=	-e 's,getopt,${LOCALBASE}/bin/getopt,'

.include <bsd.port.pre.mk>

# Fix building it with clang 11
.if ${OSVERSION} >= 1300000
CFLAGS+=	-fcommon
.endif

.if ${PYTHON_SUFFIX} > 36
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-cts_remote.py \
		${PATCHDIR}/extra-patch-cts_watcher.py
.endif

post-patch: post-patch-common
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_failcount
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_master
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_report.in
	@${REINPLACE_CMD} ${REPLACE_ARGS_GETOPT} ${WRKSRC}/tools/crm_standby

.include <bsd.port.post.mk>
