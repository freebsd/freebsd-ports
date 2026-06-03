PORTNAME=	step-certificates
DISTVERSIONPREFIX=	v
DISTVERSION=	0.30.2
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step_ca certificates server
WWW=		https://smallstep.com/certificates/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	step:security/step-cli

USES=		go:modules

USE_RC_SUBR=	step_ca

GO_MODULE=	github.com/smallstep/certificates

GO_TARGET=	./cmd/step-ca:${PREFIX}/sbin/step-ca

GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${DISTVERSION}"

USERS=		step
GROUPS=		step

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/step
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${CHANGELOG.md CONTRIBUTING.md README.md SECURITY.md \
		:L:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
