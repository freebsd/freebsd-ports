# Created by: James Hunt <james.hunt@ubuntu.com>
# $FreeBSD$

PORTNAME=	procenv
PORTVERSION=	0.51
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to show process environment

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlwf:textproc/expat2

USES=		autoreconf gmake perl5
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	jamesodhunt

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
