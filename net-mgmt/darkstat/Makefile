PORTNAME=	darkstat
DISTVERSION=	3.0.721
CATEGORIES=	net-mgmt

MAINTAINER=	emikulic@gmail.com
COMMENT=	Network statistics gatherer and reporter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPL

USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	emikulic
GH_PROJECT=	darkstat
USE_RC_SUBR=	darkstat

GNU_CONFIGURE=	yes

PLIST_FILES=	man/man8/darkstat.8.gz \
		sbin/darkstat
PORTDOCS=	AUTHORS INSTALL README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
