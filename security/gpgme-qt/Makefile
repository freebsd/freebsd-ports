.if ${FLAVOR:U} == qt5
PORTREVISION=	0

COMMENT=	Gpgme Qt5 bindings
.else
PORTREVISION=	0

COMMENT=	Gpgme Qt6 bindings
.endif

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MASTERDIR=	${.CURDIR}/../../security/gpgme
SLAVEPORT=	qt
BINDING_NAME=	qt
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
