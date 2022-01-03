PORTNAME=	nsysctl
DISTVERSION=	2.1
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Utility to get and set kernel state at runtime

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsysctlmibinfo2.so:devel/libsysctlmibinfo2

USE_GITLAB=	yes

GL_ACCOUNT=	alfix
GL_COMMIT=	b6520605830a56913ca3ca6dfa0bf20f8f4e8ca1

PLIST_FILES=	man/man8/${PORTNAME}.8.gz \
		sbin/${PORTNAME}
PORTDOCS=	CHANGELOG
PORTEXAMPLES=	file.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

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
