PORTNAME=	topgrade
DISTVERSIONPREFIX=	v
DISTVERSION=	10.0.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	freebsd@scd-systems.net
COMMENT=	Tool for upgrade everything
WWW=		https://crates.io/crates/topgrade-rs/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	topgrade-rs

PLIST_FILES=	bin/topgrade \
		man/man8/topgrade.8.gz
PORTEXAMPLES=	config.example.toml

OPTIONS_DEFINE=	EXAMPLES

# sys-info-0.9.1 crate fix: https://github.com/FillZpp/sys-info-rs/issues/80
post-patch:
	@${REINPLACE_CMD} \
	-e '/get_cpu/s|unsigned long|uint64_t|' \
	-e '/get_proc_total/s|unsigned long|uint64_t|' \
	${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${INSTALL_MAN} ${WRKSRC}/topgrade.8 ${STAGEDIR}${PREFIX}/man/man8/

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
