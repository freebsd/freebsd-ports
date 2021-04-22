# Created by: James Hunt <james.hunt@ubuntu.com>

PORTNAME=	procenv
DISTVERSION=	0.55
CATEGORIES=	sysutils

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Utility to show process environment

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlwf:textproc/expat2
LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		autoreconf localbase perl5

USE_GITHUB=	yes
GH_ACCOUNT=	jamesodhunt
USE_PERL5=	build

GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/procenv \
		man/man1/procenv.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^PKG_/d' ${WRKSRC}/configure.ac

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
