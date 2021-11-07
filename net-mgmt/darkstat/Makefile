# Created by: Anders Nordby <anders@FreeBSD.org>

PORTNAME=	darkstat
PORTVERSION=	3.0.719
CATEGORIES=	net-mgmt
MASTER_SITES=	https://unix4lyfe.org/darkstat/

MAINTAINER=	emikulic@gmail.com
COMMENT=	Network statistics gatherer and reporter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

USES=		tar:bzip2
GNU_CONFIGURE=	yes

USE_RC_SUBR=	darkstat

PORTDOCS=	AUTHORS INSTALL README
PLIST_FILES=	sbin/darkstat man/man8/darkstat.8.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
