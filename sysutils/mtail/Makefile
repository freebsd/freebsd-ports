PORTNAME=	mtail
DISTVERSION=	3.0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Extract internal monitoring data from application logs
WWW=		https://github.com/google/mtail

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_TARGET=	./cmd/mtail ./cmd/mfmt

USE_GITHUB=	yes
GH_ACCOUNT=	google

USE_RC_SUBR=	mtail

SUB_FILES+=	pkg-message
SUB_LIST=	USERS=${USERS} \
		ETCDIR=${ETCDIR} \
		DOCSDIR=${DOCSDIR} \
		EXAMPLESDIR=${EXAMPLESDIR}

USERS=	mtail
GROUPS=	mtail

DOCS=	docs/*.md
EXAMPLES=	examples/*.mtail

OPTIONS_DEFINE=	DOCS EXAMPLES

# make gomod-vendor > Makefile.gomod
.include "${.CURDIR}/Makefile.gomod"

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
