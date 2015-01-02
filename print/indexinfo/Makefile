# $FreeBSD$

PORTNAME=	indexinfo
PORTVERSION=	0.2.2
CATEGORIES=	print ports-mgmt
MASTER_SITES=	http://files.etoilebsd.net/indexinfo/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Utility to regenerate the GNU info page index

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-mode
PLIST_FILES=	bin/indexinfo
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
