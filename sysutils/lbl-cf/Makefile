# Created by: Craig Leres <leres@FreeBSD.org>

PORTNAME=	cf
PORTVERSION=	1.2.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ee.lbl.gov/
PKGNAMEPREFIX=	lbl-

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Unix time to formatted time and date filter

LICENSE=	BSD3CLAUSE

INSTALL_TARGET=	install install-man

PLIST_FILES=	bin/cf \
		man/man1/cf.1.gz

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	cf # bin/cf

pre-install:
	@${STRIP_CMD} ${WRKSRC}/cf

.include <bsd.port.mk>
