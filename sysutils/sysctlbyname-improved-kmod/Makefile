# $FreeBSD$

PORTNAME=	sysctlbyname-improved-kmod
DISTVERSION=	20191124
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Internal sysctl node to implement an improved sysctlbyname(3) clone

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod
USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlbyname-improved
GL_COMMIT=	522eb1f40c46a035c563f4f88594db5803ccf462

PLIST_FILES=	${KMODDIR}/sysctlbyname_improved.ko

PORTEXAMPLES=	sysctlbyname_improved.h \
		sysctlbyname_improved.c \
		sysctlbyname_improved_example.c

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
