# New ports collection makefile for:   py-synce-librapi2
# Date created:                19 June 2008
# Whom:                        Ilya Bakulin <webmaster@kibab.com>
#
# $FreeBSD$

CATEGORIES=	palm python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}synce-

MAINTAINER=	webmaster@kibab.com
COMMENT=	Python bindings for libRAPI2

LIB_DEPENDS=	rapi.2:${PORTSDIR}/palm/synce-librapi2
BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

MASTERDIR=	${.CURDIR}/../synce-librapi2

USE_PYTHON=	yes

PLIST=		${.CURDIR}/pkg-plist

RAPI_SLAVE=	pythonb

pre-patch:
	@${REINPLACE_CMD} -e 's|$$(top_builddir)/src/librapi.la|${LOCALBASE}/lib/librapi.la|g' \
		${WRKSRC}/python/Makefile.in

do-build:
	@(cd ${WRKSRC}/python && ${MAKE})

do-install:
	@(cd ${WRKSRC}/python && ${MAKE} install)

.include "${MASTERDIR}/Makefile"
