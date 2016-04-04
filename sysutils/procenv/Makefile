# Created by: James Hunt <james.hunt@ubuntu.com>
# $FreeBSD$

PORTNAME=	procenv
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/procenv/trunk/${PORTVERSION}/+download/ \
		http://people.canonical.com/~jhunt/debian/procenv/${PORTVERSION}/ \
		DEBIAN

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to show process environment

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlwf:textproc/expat2

USES=		autoreconf gmake perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build
TEST_TARGET=	check

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PLIST_FILES=	bin/procenv \
		man/man1/procenv.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
