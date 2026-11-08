PORTNAME=	time
DISTVERSION=	1.10
CATEGORIES=	sysutils
MASTER_SITES=	GNU
PKGNAMEPREFIX=	g

MAINTAINER=	bcallaha@monmouth.edu
COMMENT=	GNU version of the time(1) utility
WWW=		https://www.gnu.org/software/time/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

TEST_TARGET=	check

INFO=		time
PLIST_FILES=	bin/gtime

.include <bsd.port.mk>
