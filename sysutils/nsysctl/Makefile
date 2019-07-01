# $FreeBSD$

PORTNAME=	nsysctl
DISTVERSION=	1.1
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get or set the kernel state supporting libxo output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo.so:devel/libsysctlmibinfo

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	e251dcf345c37e83d39f6fe93f0af2adf62da282

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}
PORTDOCS=	CHANGELOG
PORTEXAMPLES=	file.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
