PORTNAME=	sysctlbyname-improved-kmod
DISTVERSION=	20221211
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Internal sysctl object to implement an improved sysctlbyname(3)
WWW=		https://gitlab.com/alfix/sysctlbyname-improved/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod
USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlbyname-improved
GL_COMMIT=	22bdff50867ff927edd098091608e871503291b6

PLIST_FILES=	${KMODDIR}/sysctlbyname_improved.ko

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

do-install:
	${INSTALL_KLD} ${WRKSRC}/sysctlbyname_improved.ko ${STAGEDIR}${KMODDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.post.mk>
