# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/ports-mgmt/packagekit-qt4/Makefile,v 1.1 2010/01/08 02:16:38 kwm Exp $

PORTREVISION=	2
PKGNAMESUFFIX=	-qt4

COMMENT=	Qt4 bindings to packagekit

IGNORE=		does not build with Qt 4.8
DEPRECATED=	Ignored for more than 5 years
EXPIRATION_DATE=	2017-09-27

MASTERDIR=	${.CURDIR}/../../ports-mgmt/packagekit
BUILD_WRKSRC=	${WRKSRC}/lib/packagekit-qt
INSTALL_WRKSRC=	${WRKSRC}/lib/packagekit-qt
SLAVEPORT=	qt4
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
