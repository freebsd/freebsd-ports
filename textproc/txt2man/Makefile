PORTNAME=	txt2man
DISTVERSIONPREFIX=	txt2man-
DISTVERSION=	1.7.1
CATEGORIES=	textproc

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Converts flat ASCII text to man page format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
RUN_DEPENDS=	gawk:lang/gawk

USES=		cpe gmake
CPE_VENDOR=	marc_vertes
USE_GITHUB=	yes
GH_ACCOUNT=	mvertes

MAKE_ENV=	prefix=${STAGEDIR}${PREFIX}
NO_ARCH=	yes

PORTSCOUT=	limit:^d\.d\.

PLIST_FILES=	bin/bookman \
		bin/src2man \
		bin/txt2man \
		share/man/man1/bookman.1.gz \
		share/man/man1/src2man.1.gz \
		share/man/man1/txt2man.1.gz

PORTDOCS=	Changelog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's,awk,gawk,' ${WRKSRC}/bookman ${WRKSRC}/src2man

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
