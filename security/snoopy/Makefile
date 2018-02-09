# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	snoopy
PORTVERSION=	2.4.6
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Log every executed command to syslog

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	socat:net/socat

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-datasource-tid_kernel \
		ac_cv_prog_SNOOPY_PROG_SOCAT_FOUND=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool shebangfix

GH_ACCOUNT=	a2o
USE_GITHUB=	yes

SHEBANG_GLOB=	*.sh

post-patch:
	@${REINPLACE_CMD} -e 's| -Wall -Werror||' ${WRKSRC}/configure.ac ${WRKSRC}/build/Makefile.am.common
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/README.md
	@${REINPLACE_CMD} -e '/#define.*_XOPEN_SOURCE/d' \
		${WRKSRC}/src/configfile.c \
		${WRKSRC}/src/datasource/sid.c \
		${WRKSRC}/src/datasource/snoopy_version.c \
		${WRKSRC}/src/snoopy.h \
		${WRKSRC}/tests/bin/snoopy-test-threads.c \
		${WRKSRC}/src/tsrm.c
	@${REINPLACE_CMD} -e '/features.h/d' ${WRKSRC}/configure.ac ${WRKSRC}/src/output/socketoutput.c ${WRKSRC}/src/snoopy.h
	@${REINPLACE_CMD} -e 's|#include <wait.h>|#include <sys/wait.h>|' ${WRKSRC}/tests/bin/snoopy-test-exec-in-threads.c ${WRKSRC}/tests/bin/snoopy-test-threads.c

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ChangeLog README.md ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} CONTRIBUTING.md FAQ.md FILTER_exclude_spawns_of.md HACKING.md INSTALL.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
