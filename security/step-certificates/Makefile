PORTNAME=	step-certificates
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step-ca certificates server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pcsc-lite>0:devel/pcsc-lite
LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
RUN_DEPENDS=	step:security/step-cli

USES=		go:modules

GO_MODULE=	github.com/smallstep/certificates

USE_RC_SUBR=	step-ca

GO_TARGET=	./cmd/step-ca:${PREFIX}/sbin/step-ca  \
		./cmd/step-cloudkms-init  \
		./cmd/step-awskms-init \
		./cmd/step-yubikey-init \
		./cmd/step-pkcs11-init

GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

USERS=		step
GROUPS=		step

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/step
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
