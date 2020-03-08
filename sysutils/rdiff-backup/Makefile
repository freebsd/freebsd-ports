# Created by: Gerhard Häring <gh@ghaering.de>
# $FreeBSD$

PORTNAME=	rdiff-backup
PORTVERSION=	1.2.8
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH \
		LOCAL/vd/${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Local/remote mirroring+incremental backup

LICENSE=	GPLv2

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=	librsync.so:net/librsync2

CONFLICTS=	rdiff-backup-devel-[0-9]* rdiff-backup-1.0*

PORTSCOUT=	limitw:1,even

USES=		python:2.7
USE_PYTHON=	distutils
USE_LDCONFIG=	yes

MAN1S=		rdiff-backup.1 rdiff-backup-statistics.1
DOCS=		CHANGELOG README COPYING FAQ.html

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${MAN1S:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.for lib in C.so _librsync.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME:S,-,_,}/${lib}
.endfor

.include <bsd.port.mk>
