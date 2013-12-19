# $FreeBSD$

PORTNAME=	entr
PORTVERSION=	2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://entrproject.org/code/ \
		https://bitbucket.org/eradman/entr/get/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Runs arbitrary commands when files change

LICENSE=	ISCL BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

WRKSRC=		${WRKDIR}/eradman-entr-c0009123230b

MAKEFILE=	Makefile.bsd
MAKE_ARGS=	MANPREFIX=${MANPREFIX}/man
PLIST_FILES=	bin/entr man/man1/entr.1.gz

.include <bsd.port.mk>
