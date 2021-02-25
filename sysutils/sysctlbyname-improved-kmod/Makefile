# $FreeBSD$

PORTNAME=	sysctlbyname-improved-kmod
DISTVERSION=	20210223
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Internal sysctl object to implement an improved sysctlbyname(3)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod
USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlbyname-improved
GL_COMMIT=	1d6119756931d05cc2526308c941c979e475d3a7

PLIST_FILES=	${KMODDIR}/sysctlbyname_improved.ko

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

.include <bsd.port.pre.mk>

# Once the sysctlinfo interface (review D21700) lands into the base tree this
# node can be added to the interface and the following statement needs
# to be expanded
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200019
IGNORE=		needs oid_label member of struct sysctl_oid defined in sysctl.h which was first introduced in FreeBSD 12
.endif
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
