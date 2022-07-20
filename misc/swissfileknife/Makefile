PORTNAME=	swissfileknife
PORTVERSION=	1.9.8
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/1-${PORTNAME}/${PORTVERSION}.0
DISTNAME=	sfk-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	One hundred command-line tools in one binary

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CPPFLAGS+=	-DVER_STR_OS=\\\"${OPSYS:tl}-${ARCH}\\\"

PLIST_FILES=	bin/sfk
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,ifndef MAC_OS_X,ifdef __linux__, ;\
		s,ifdef MAC_OS_X,ifdef __FreeBSD__,' ${WRKSRC}/sfkbase.hpp
	@${REINPLACE_CMD} -e 's,defined(MAC_OS_X) || defined(SOLARIS),&\
		|| defined(__FreeBSD__),' \
			${WRKSRC}/sfk.cpp ${WRKSRC}/sfkext.cpp
	@${REINPLACE_CMD} -e '/_STDINT_H/,+6d' ${WRKSRC}/sfkmatch.hpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
