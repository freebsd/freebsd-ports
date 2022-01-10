PORTNAME=	dateutils
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://bitbucket.org/hroptatyr/dateutils/downloads/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	Command line utilities for working with dates

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man

USES=		tar:xz
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	py*-dateutils

INFO=		dateutils

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
