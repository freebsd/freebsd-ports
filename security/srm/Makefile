PORTNAME=	srm
PORTVERSION=	1.2.15
PORTREVISION=	1
CATEGORIES=	security sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION} \
		SF/${PORTNAME}/old_releases \
		SF/${PORTNAME}/old_releases/${PORTVERSION}

MAINTAINER=	mshirk@daemon-security.com
COMMENT=	Secure rm, a utility which destroys file contents before unlinking
WWW=		https://sourceforge.net/projects/srm/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	secure_delete

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
TEST_TARGET=	test

PLIST_FILES=	bin/fill_test bin/srm share/man/man1/srm.1.gz

.include <bsd.port.mk>
