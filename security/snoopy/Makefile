# Created by: Philippe Audeoud <jadawin@tuxaco.net>

PORTNAME=	snoopy
PORTVERSION=	2.4.15
CATEGORIES=	security
MASTER_SITES=	https://github.com/a2o/snoopy/releases/download/snoopy-${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Log every executed command to syslog

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	socat:net/socat

USES=		autoreconf gmake libtool shebangfix

CONFIGURE_ARGS=	--disable-datasource-tid_kernel \
		ac_cv_prog_SNOOPY_PROG_SOCAT_FOUND=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/README.md

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ChangeLog README.md ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} CONTRIBUTING.md FAQ.md FILTER_exclude_spawns_of.md INSTALL.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
