PORTNAME=	legion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	sysutils

MAINTAINER=	grepjava@gmail.com
COMMENT=	Container orchestrator built on jails, ZFS, pf and WireGuard
WWW=		https://github.com/grepjava/legion

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	tested on these only

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	grepjava

CARGO_INSTALL_PATH=	crates/legion

PORTDOCS=	CLI.md DESIGN.md README.md

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1500000
IGNORE=		needs FreeBSD 15 or newer
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/legion
	${SED} -e 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/packaging/freebsd/rc.d/legion > ${WRKDIR}/legion.rc
	${INSTALL_SCRIPT} ${WRKDIR}/legion.rc ${STAGEDIR}${PREFIX}/etc/rc.d/legion
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKSRC}/packaging/freebsd/newsyslog.conf.d/legion.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/legion.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/legion/volume
	${INSTALL_MAN} ${WRKSRC}/man/legion.1 ${STAGEDIR}${PREFIX}/share/man/man1/legion.1

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/volume-plugins
.for f in hostpath rclone sshfs
	${INSTALL_SCRIPT} ${WRKSRC}/packaging/volume-plugins/${f} \
		${STAGEDIR}${EXAMPLESDIR}/volume-plugins/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/packaging/volume-plugins/README.md \
		${STAGEDIR}${EXAMPLESDIR}/volume-plugins/README.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/CLI.md ${WRKSRC}/docs/DESIGN.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
