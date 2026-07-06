PORTNAME=	ntpd-rs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	net

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Full-featured implementation of the Network Time Protocol
WWW=		https://tweedegolf.nl/en/pendulum

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	the ring crate requires SSE2 instruction on intel cpu

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	pendulum-project

USE_RC_SUBR=	ntp_daemon

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

BINFILES=	ntp-ctl ntp-daemon ntp-metrics-exporter

post-patch:
	@${REINPLACE_CMD} 's|%%ETCDIR%%|${ETCDIR}|' \
	    ${PATCH_WRKSRC}/ntpd/src/daemon/config/mod.rs

do-install:
.for f in ${BINFILES}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/*/${f} ${STAGEDIR}${LOCALBASE}/bin
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/ntp.server.toml ${STAGEDIR}${ETCDIR}/ntp.server.toml.sample
	${INSTALL_DATA} ${WRKSRC}/docs/examples/conf/ntp.toml.default ${STAGEDIR}${ETCDIR}/ntp.toml.sample

do-install-MANPAGES-on:
.for i in 5 8
	${INSTALL_MAN} ${WRKSRC}/docs/precompiled/man/*.${i} ${STAGEDIR}${PREFIX}/share/man/man${i}/
.endfor

.include <bsd.port.mk>
