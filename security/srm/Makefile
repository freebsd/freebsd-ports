# Created by: Keith J. Jones <kjones@antihackertoolkit.com>
# $FreeBSD$

PORTNAME=	srm
PORTVERSION=	1.2.15
CATEGORIES=	security sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION} \
		SF/${PORTNAME}/old_releases \
		SF/${PORTNAME}/old_releases/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure rm, a utility which destroys file contents before unlinking

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	secure_delete-[0-9]*

GNU_CONFIGURE=	yes
TEST_TARGET=	test

PLIST_FILES=	bin/fill_test bin/srm man/man1/srm.1.gz

.include <bsd.port.mk>
