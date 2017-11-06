# $FreeBSD$

PORTNAME=	dateutils
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	https://bitbucket.org/hroptatyr/dateutils/downloads/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Command line utilities for working with dates

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man

BROKEN_powerpc64=	fails to compile: sysctl.h: expected declaration specifiers or ... before u_int

USES=		pathfix tar:xz
GNU_CONFIGURE=	yes

INFO=		dateutils

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
