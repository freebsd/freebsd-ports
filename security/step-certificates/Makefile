PORTNAME=	step-certificates
DISTVERSIONPREFIX=	v
DISTVERSION=	0.28.4
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step_ca certificates server
WWW=		https://smallstep.com/certificates/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pcsc-lite>0:devel/pcsc-lite
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	step:security/step-cli

USES=		go:1.22,modules

USE_RC_SUBR=	step_ca

GO_MODULE=	github.com/smallstep/certificates

GO_TARGET=	./cmd/step-ca:${PREFIX}/sbin/step-ca

GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

USERS=		step
GROUPS=		step

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/step
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/CONTRIBUTING.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/SECURITY.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
