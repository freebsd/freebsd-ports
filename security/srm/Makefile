# Created by: Keith J. Jones <kjones@antihackertoolkit.com>
# $FreeBSD$

PORTNAME=	srm
PORTVERSION=	1.2.12
CATEGORIES=	security sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION} \
			${PORTNAME}/old_releases \
			${PORTNAME}/old_releases/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure rm, a utility which destroys file contents before unlinking

LICENSE=	MIT

CONFLICTS=	secure_delete-[0-9]*
USES=	tar:bzip2

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/srm man/man1/srm.1.gz

.include <bsd.port.mk>
