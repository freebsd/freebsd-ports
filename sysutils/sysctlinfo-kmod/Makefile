PORTNAME=	sysctlinfo-kmod
DISTVERSION=	20221211
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Kernel sysctl MIB-Tree interface
WWW=		https://gitlab.com/alfix/sysctlinfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod
USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlinfo
GL_TAGNAME=	be57d5a892d0a908172664f87afeed0627e9ddf2

PLIST_FILES=	${KMODDIR}/sysctlinfo.ko \
		include/sysctlinfo.h \
		share/man/man3/sysctlinfo.3.gz \
		share/man/man4/sysctlinfo.4.gz

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

do-install:
	${INSTALL_KLD} ${WRKSRC}/sysctlinfo.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_DATA} ${WRKSRC}/sysctlinfo.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/sysctlinfo.3 ${STAGEDIR}${PREFIX}/share/man/man3
	${INSTALL_MAN} ${WRKSRC}/sysctlinfo.4 ${STAGEDIR}${PREFIX}/share/man/man4

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.post.mk>
