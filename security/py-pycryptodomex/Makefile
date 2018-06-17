# $FreeBSD$

PKGNAMESUFFIX=	x

CONFLICTS_INSTALL=

MASTERDIR=	${.CURDIR}/../py-pycryptodome

NAMESPACE=	Cryptodome

pre-build:
	@${TOUCH} ${WRKSRC}/.separate_namespace

.include "${MASTERDIR}/Makefile"
