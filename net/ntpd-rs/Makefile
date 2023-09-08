PORTNAME=	ntpd-rs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Full-featured implementation of the Network Time Protocol
WWW=		https://tweedegolf.nl/en/pendulum

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_RC_SUBR=	ntp_daemon
USERS=		_ntp
GROUPS=		_ntp

USE_GITHUB=	yes
GH_ACCOUNT=	pendulum-project

BINFILES=	demobilize-server ntp-ctl ntp-daemon ntp-metrics-exporter nts-ke nts-ke-server peer-state rate-limit-server simple-daemon
SAMPLEFILES=	ntp.server.toml ntp.toml

post-patch:
	@${REINPLACE_CMD} 's|%%ETCDIR%%|${ETCDIR}|' ${WRKSRC}/ntp-daemon/src/config/mod.rs

do-install:
.for f in ${BINFILES}
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/${f} ${STAGEDIR}${LOCALBASE}/bin
.endfor

	${MKDIR} ${STAGEDIR}${ETCDIR}
.for f in ${SAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

.include <bsd.port.mk>
