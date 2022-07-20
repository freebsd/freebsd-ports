PORTNAME=	runit
PORTVERSION=	2.1.2
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Service supervision tools compatible with DJB daemontools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/package/COPYING

BROKEN_mips=		fails to install: runit-init failed
BROKEN_mips64=		fails to install: runit-init failed

USES=		cpe

USE_RC_SUBR=	runsvdir
WRKSRC=		${WRKDIR}/admin/${DISTNAME}

SERVICE_DIR?=	/var/service
SUB_FILES=	pkg-message
SUB_LIST=	SERVICE_DIR="${SERVICE_DIR}"
PORTDOCS=	*

DOCS=		package/CHANGES package/README \
		package/THANKS doc/*.html
CONFIG=		etc/freebsd/1 etc/2 etc/freebsd/3 etc/freebsd/ctrlaltdel \
		etc/freebsd/getty-ttyv4/run etc/freebsd/getty-ttyv4/finish \
		etc/freebsd/getty-ttyv4/whichtty

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -i '' 's!/service/!${SERVICE_DIR}!' \
		${PATCH_WRKSRC}/man/* ${PATCH_WRKSRC}/src/sv.c
	${REINPLACE_CMD} -i '' '\|^PATH=|s|$$|:${PREFIX}/bin:${PREFIX}/sbin|' \
		${PATCH_WRKSRC}/etc/freebsd/3
	${FIND} ${PATCH_WRKSRC} -name '*.orig' -delete

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc
	${ECHO_CMD} "${CC}" > ${WRKSRC}/src/conf-ld
	${ECHO_CMD} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/src/runit.h

do-build:
	cd ${WRKSRC} && package/compile && package/check
	@${MKDIR} ${WRKDIR}/etc/getty-ttyv4
.for file in ${CONFIG}
	@${SED} -e 's!/etc/runit!${ETCDIR}!g' \
		-e 's!/service!${SERVICE_DIR}!g' \
		-e 's!/usr/local!${PREFIX}!g' \
		${WRKSRC}/${file} > ${WRKDIR}/${file:S!freebsd/!!}.sample
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/command/* ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/man/* ${STAGEDIR}${PREFIX}/man/man8/
	@${MKDIR} ${STAGEDIR}${ETCDIR}/getty-ttyv4
	${INSTALL_SCRIPT} ${WRKDIR}/etc/[123c]* ${STAGEDIR}${ETCDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/etc/getty-ttyv4/* \
		${STAGEDIR}${ETCDIR}/getty-ttyv4

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
