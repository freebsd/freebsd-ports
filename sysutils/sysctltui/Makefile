PORTNAME=	sysctltui
DISTVERSION=	0.0.2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get and set kernel state at runtime
WWW=		https://gitlab.com/alfix/sysctltui/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbsddialog.so:devel/bsddialog \
		libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USE_GITLAB=	yes
GL_ACCOUNT=	alfix

PLIST_FILES=	sbin/${PORTNAME} \
		share/man/man8/${PORTNAME}.8.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8/

.include <bsd.port.post.mk>
