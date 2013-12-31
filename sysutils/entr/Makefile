# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	2.5
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/ \
		https://bitbucket.org/eradman/entr/get/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

# This software has code under BSD[23]CLAUSE licenses.
# All the code used in FreeBSD is under ISCL license.
LICENSE=	ISCL

WRKSRC=		${WRKDIR}/eradman-entr-7821588c309c

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
PLIST_FILES=	bin/entr man/man1/entr.1.gz

.include <bsd.port.mk>
