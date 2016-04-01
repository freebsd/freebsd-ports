# Created by: Hiten Pandya <hiten@uk.FreeBSD.org>
# $FreeBSD$

PORTNAME=	larbin
PORTVERSION=	2.6.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP crawler with an easy interface

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash \
		makedepend:devel/makedepend

USES=		gmake shebangfix
SHEBANG_FILES=	configure
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

PORTDOCS=	*
PLIST_FILES=	bin/larbin etc/larbin.conf.sample

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG} "====================================================================="
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Make sure you have a look at the larbin documentation available at:"
	@${ECHO_MSG} "  http://larbin.sourceforge.net/custom-eng.html."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "====================================================================="

post-extract:
	@(cd ${WRKSRC}/src/utils && ${MV} string.h mystring.h)

post-patch:
	@${REINPLACE_CMD} -e \
		'/CC=/s|echo|${TRUE:T}| ; \
		 /CXX=/s|echo|${TRUE:T}| ; \
		 /-lpthread/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|CFLAGS:=-O3|CFLAGS+=| ; \
		 s|CXXFLAGS:=|CXXFLAGS+=| ; \
		 s|-O3|| ; \
		 s|-I-||' ${WRKSRC}/src/larbin.make
	@${REINPLACE_CMD} -e \
		'/delete \[\] tab/s|^|//|' ${WRKSRC}/src/utils/histogram.cc
	@${FIND} ${WRKSRC}/src -name "*.cc" -or -name "*.h" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|utils/string.h|utils/mystring.h| ; \
		 s|<iostream.h>|<iostream>| ; \
		 s|<string.h>|<cstring>| ; \
		 s|\([[:blank:]]\)cerr|\1std::cerr|g ; \
		 s|\([[:blank:]]\)cout|\1std::cout|g ; \
		 s|\([[:blank:]]\)endl|\1std::endl|g'

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} larbin \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} larbin.conf \
		${STAGEDIR}${PREFIX}/etc/larbin.conf.sample)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
