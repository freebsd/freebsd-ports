# New ports collection makefile for:	samba-python
# Date created:				01 May 2004
# Whom:					Timur Bakeyev <timur@gnu.org>
#
# $FreeBSD$
#

PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		net python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

COMMENT=		Python bindings for Samba

CONFLICTS=

SAMBA_PORT=		samba3
SAMBA_SUBPORT=		yes

MASTERDIR=		${.CURDIR}/../${SAMBA_PORT}
PKGDIR=			${.CURDIR}

USE_PYTHON=		2.1+
USE_PYDISTUTILS=	yes
PYSETUP=		python/setup.py

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python

do-build:
	cd ${WRKSRC} && ${MAKE} proto
	cd ${WRKSRC} && ${MAKE} python_ext

post-install:
	-@${MKDIR} ${EXAMPLESDIR}
	@${CP} -Rp ${WRKSRC}/python/examples/* ${EXAMPLESDIR}
	@${CP} -Rp ${WRKDIR}/${DISTNAME}/examples/scripts/shares/python/* \
	    ${EXAMPLESDIR}

.include "${MASTERDIR}/Makefile"
