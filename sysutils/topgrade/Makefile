PORTNAME=	topgrade
DISTVERSIONPREFIX=	v
DISTVERSION=	15.0.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	freebsd@scd-systems.net
COMMENT=	Tool for upgrade everything
WWW=		https://github.com/topgrade-rs/topgrade

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	sudo:security/sudo

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	topgrade-rs

PLIST_FILES=	bin/topgrade \
		share/man/man1/topgrade.1.gz
PORTEXAMPLES=	config.example.toml

OPTIONS_DEFINE=	EXAMPLES

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
		${STAGEDIR}${PREFIX}/bin/${PORTNAME} --gen-manpage > ${WRKSRC}/${PORTNAME}.1
		${INSTALL_MAN} ${WRKSRC}/topgrade.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
