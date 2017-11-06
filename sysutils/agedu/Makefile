# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	agedu
PORTVERSION=	20170831
DISTVERSIONSUFFIX=	.fc6b2b5
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/sunpoet \
		https://www.chiark.greenend.org.uk/~sgtatham/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unix utility for tracking down wasted disk space

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|HOST_NAME_MAX|_POSIX_&|' ${WRKSRC}/httpd.c

.include <bsd.port.mk>
