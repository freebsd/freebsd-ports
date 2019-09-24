# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	1.2
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get or set the kernel state supporting libxo output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/sysctlinfo.h:sysutils/sysctlinfo-kmod
LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo
RUN_DEPENDS=	${KMODDIR}/sysctlinfo.ko:sysutils/sysctlinfo-kmod

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	5d7875fbeca8d5ae31dffac6ec1f12346e380e5a

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}
PORTDOCS=	CHANGELOG
PORTEXAMPLES=	file.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200019
IGNORE=		needs oid_label constant in sysctl.h which was first introduced in FreeBSD 12
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
