PORTNAME=	apiary
DISTVERSIONPREFIX=	release/
DISTVERSION=	1.0.0.a0
CATEGORIES=	net-mgmt

MAINTAINER=	gjb@FreeBSD.org
COMMENT=	Distributed virtualization control plane for FreeBSD Combs
WWW=		https://apiary.work

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# git reads the commit id out of the distfile's pax global header.
BUILD_DEPENDS=	git:devel/git@lite
RUN_DEPENDS=	dnsmasq:dns/dnsmasq

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	glenjbarber
GH_PROJECT=	apiary

# USE_RC_SUBR installs the rc.d scripts and adds them to the packing
# list; they are not listed in PLIST_FILES.
USE_RC_SUBR=	apiary_raftd apiary_managerd apiary_frontend apiary_restshimd \
		apiary_mcp

GO_MOD_DIST=	github
GO_MODULE=	github.com/glenjbarber/apiary

# Apiary's own binaries live in libexec, not bin: they are daemons and
# operator tools, not something an operator types by bare name. The
# rc.d scripts exec ${PREFIX}/libexec/apiary/<name> by absolute path,
# so this path is load-bearing and must match the PLIST_SUB below.
_APIARY_LIBEXECDIR=	${PREFIX}/libexec/apiary
_APIARY_SBINDIR=	${PREFIX}/sbin
_APIARY_CONFDIR=	${PREFIX}/etc/apiary
_APIARY_DATADIR=	/var/db/apiary
_APIARY_LOGDIR=		/var/log/apiary
_APIARY_RUNDIR=		/var/run/apiary

GO_TARGET=	./cmd/apiary-mcp:${_APIARY_LIBEXECDIR}/apiary-mcp \
		./cmd/apiaryctl:${_APIARY_SBINDIR}/apiaryctl \
		./cmd/apiaryinstall:${_APIARY_LIBEXECDIR}/apiaryinstall \
		./cmd/frontend:${_APIARY_LIBEXECDIR}/frontend \
		./cmd/managerd:${_APIARY_LIBEXECDIR}/managerd \
		./cmd/raftd:${_APIARY_LIBEXECDIR}/raftd \
		./cmd/restshimd:${_APIARY_LIBEXECDIR}/restshimd

# The stamp is derived from the distfile, not hard-coded: GitHub's
# source archives carry the commit in their pax global header, and the
# tarball's member mtimes are the commit's own date.
pre-build:
	@commit=$$(gzip -dc ${_DISTDIR}/${DISTFILES:M*.tar.gz} 2>/dev/null | \
		git get-tar-commit-id) ; \
	if [ -z "$$commit" ] ; then \
		${ECHO_MSG} "===>  ERROR: the distfile carries no commit id." ; \
		${ECHO_MSG} "    The build stamp is derived from the tarball's pax" ; \
		${ECHO_MSG} "    global header, and this one has none." ; \
		exit 1 ; \
	fi ; \
	time=$$(stat -f '%m' ${WRKSRC} 2>/dev/null | \
		${XARGS} -I{} date -u -r {} +%Y-%m-%dT%H:%M:%SZ) ; \
	if [ -z "$$time" ] ; then \
		${ECHO_MSG} "===>  ERROR: could not read the commit date from the distfile." ; \
		exit 1 ; \
	fi ; \
	id=$$(${PRINTF} %s "$$commit" | cut -c1-12) ; \
	${ECHO_MSG} "===>  Stamping the build with commit $$id ($$time)" ; \
	${PRINTF} '_APIARY_BUILD_COMMIT=$$commit\n_APIARY_BUILD_ID=$$id\n_APIARY_BUILD_TIME=$$time\n' \
		> ${WRKDIR}/.buildinfo

GO_BUILDFLAGS+=	-ldflags "-X github.com/glenjbarber/apiary/internal/buildinfo.BuildID=${_APIARY_BUILD_ID} -X github.com/glenjbarber/apiary/internal/buildinfo.BuildTime=${_APIARY_BUILD_TIME} -X github.com/glenjbarber/apiary/internal/buildinfo.GitCommit=${_APIARY_BUILD_COMMIT}"

SUB_FILES=	README.md

# Recursive, so they are read after pre-build has written the file.
_APIARY_BUILD_COMMIT=	$$(sed -n 's/^_APIARY_BUILD_COMMIT=//p' ${WRKDIR}/.buildinfo)
_APIARY_BUILD_ID=	$$(sed -n 's/^_APIARY_BUILD_ID=//p' ${WRKDIR}/.buildinfo)
_APIARY_BUILD_TIME=	$$(sed -n 's/^_APIARY_BUILD_TIME=//p' ${WRKDIR}/.buildinfo)

# The runtime directories the package creates and owns. They are
# recorded with PLIST_DIRS so that `pkg info` shows them and `pkg
# delete` removes the ones that are empty.
PLIST_DIRS=	${_APIARY_DATADIR} \
		${_APIARY_DATADIR}/isos \
		${_APIARY_DATADIR}/raftd \
		${_APIARY_LOGDIR} \
		${_APIARY_RUNDIR}

PLIST_FILES=	"@sample ${_APIARY_CONFDIR}/frontend.json.sample" \
		"@sample ${_APIARY_CONFDIR}/managerd.json.sample" \
		"@sample ${_APIARY_CONFDIR}/raftd.json.sample" \
		${_APIARY_CONFDIR}/README.md \
		"@sample ${_APIARY_CONFDIR}/restshimd.json.sample" \
		${_APIARY_LIBEXECDIR}/apiary-mcp \
		${_APIARY_LIBEXECDIR}/apiaryinstall \
		${_APIARY_LIBEXECDIR}/frontend \
		${_APIARY_LIBEXECDIR}/managerd \
		${_APIARY_LIBEXECDIR}/raftd \
		${_APIARY_LIBEXECDIR}/restshimd \
		sbin/apiaryctl

PLIST_SUB=	_APIARY_CONFDIR=${_APIARY_CONFDIR} \
		_APIARY_DATADIR=${_APIARY_DATADIR} \
		_APIARY_LIBEXECDIR=${_APIARY_LIBEXECDIR} \
		_APIARY_LOGDIR=${_APIARY_LOGDIR} \
		_APIARY_RUNDIR=${_APIARY_RUNDIR}

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS QCOW2
OPTIONS_DEFAULT=	DOCS QCOW2
QCOW2_DESC=		qcow2 disk image support (measure/expand via qemu-img)
QCOW2_RUN_DEPENDS=	qemu-img:emulators/qemu

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${_APIARY_CONFDIR}
	@for s in README.md frontend.json.sample managerd.json.sample raftd.json.sample \
		restshimd.json.sample ; \
		do ${INSTALL_DATA} ${WRKSRC}/etc/apiary/$$s ${STAGEDIR}${_APIARY_CONFDIR}/$$s.tmp ; \
		${MV} ${STAGEDIR}${_APIARY_CONFDIR}/$$s.tmp \
		${STAGEDIR}${_APIARY_CONFDIR}/$$s ; \
		done
	@${MKDIR} ${STAGEDIR}${_APIARY_DATADIR}/raftd
	@${MKDIR} ${STAGEDIR}${_APIARY_DATADIR}/isos
	@${MKDIR} ${STAGEDIR}${_APIARY_RUNDIR}
	@${MKDIR} ${STAGEDIR}${_APIARY_LOGDIR}

.include <bsd.port.mk>
