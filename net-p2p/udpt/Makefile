# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	udpt
DISTVERSION=	g20200202
CATEGORIES=	net-p2p

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight UDP torrent tracker

LICENSE=	GPLv3+

USES=		gmake localbase:ldflags sqlite:3
USE_GITHUB=	yes
GH_ACCOUNT=	troydm
GH_TAGNAME=	6a7bf22

CXXFLAGS+=	-Dlinux		# easier than patch a dozen places

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/VERSION/ { s,beta,&-g${GH_TAGNAME},; \
		s,Linux,${OPSYS},; }' ${WRKSRC}/src/multiplatform.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Alternative to DOS2UNIX_FILES that preserves original timestamps,
# to be used together with `-l' switch added to PATCH_ARGS below.
fixpatches:
	@${FIND} ${FILESDIR} -name patch-* | ${XARGS} ${SED} -i '' \
		-E 's,[[:cntrl:]]*$$,,'
PATCH_ARGS+=	-l
