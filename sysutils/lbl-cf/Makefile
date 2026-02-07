PORTNAME=	cf
PORTVERSION=	1.2.8
CATEGORIES=	sysutils
MASTER_SITES=	https://ee.lbl.gov/downloads/cf/ \
		LOCAL/leres/cf
PKGNAMEPREFIX=	lbl-

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Unix time to formatted time and date filter
WWW=		https://ee.lbl.gov/

LICENSE=	BSD3CLAUSE

INSTALL_TARGET=	install install-man

PLIST_FILES=	bin/cf \
		share/man/man1/cf.1.gz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS_INSTALL=	cf # bin/cf

pre-install:
	@${STRIP_CMD} ${WRKSRC}/cf

.include <bsd.port.mk>
