PORTREVISION=	0
PKGNAMESUFFIX=	-${SLAVEPORT}

COMMENT=	Shared headers for the Gpgme Qt bindings

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MASTERDIR=	${.CURDIR}/../../security/gpgme
SLAVEPORT=	qt-headers
BINDING_NAME=	qt
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
