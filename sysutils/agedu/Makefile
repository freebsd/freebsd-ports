# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	agedu
PORTVERSION=	20200206.963bc9d
CATEGORIES=	sysutils
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/agedu/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unix utility for tracking down wasted disk space

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/agedu \
		man/man1/agedu.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|HOST_NAME_MAX|_POSIX_&|' ${WRKSRC}/httpd.c

.include <bsd.port.mk>
