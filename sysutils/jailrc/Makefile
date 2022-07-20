PORTNAME=	jailrc
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Improved jail startup/shutdown script

NO_BUILD=	yes
NO_ARCH=	yes
NO_INSTALL=	yes
USE_RC_SUBR=	jailrc
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/README ${STAGEDIR}${DOCSDIR}/README

.include <bsd.port.mk>
