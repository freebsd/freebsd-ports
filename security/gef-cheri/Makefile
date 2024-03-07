PORTNAME=	gef-cheri
DISTVERSION=	${GEF_VERSION}
PORTREVISION=	0
CATEGORIES=	security python

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	gef
GH_TAGNAME=	${GEF_COMMIT}

MAINTAINER=	zyj20@cl.cam.ac.uk
COMMENT=	GDB Enhanced Features for exploit devs & reversers with support for the Arm Morello architecture
WWW=		https://github.com/CTSRD-CHERI/gef

_UTILITY_NAME=	gef.py

.include "${.CURDIR}/Makefile.snapshot"

SLAVE_PORT=	${PORTNAME}
GEFDIR=		${.CURDIR}/../gef
DESCR=		${GEFDIR}/pkg-descr
.include "${GEFDIR}/Makefile"
