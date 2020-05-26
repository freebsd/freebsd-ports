# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hw-probe
DISTVERSION=	1.6-beta
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Probe for hardware, check operability, and find drivers

LICENSE=	LGPL21+

RUN_DEPENDS=	curl:ftp/curl \
		dmidecode:sysutils/dmidecode \
		hwstat:sysutils/hwstat \
		lscpu:sysutils/lscpu \
		smartctl:sysutils/smartmontools

USE_GITHUB=	yes
GH_ACCOUNT=	linuxhw

USES=		perl5
USE_PERL5=	run
MAKE_ARGS=	prefix=${PREFIX}
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	NEWS.md README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
