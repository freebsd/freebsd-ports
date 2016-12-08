# Created by: ache
# $FreeBSD$

PORTNAME=	authforce
PORTVERSION=	0.9.9
PORTREVISION=	4
CATEGORIES=	security www
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP authentication brute forcer

LICENSE=	GPLv2

NO_CCACHE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	zlandau

USES=		ncurses readline tar:bzip2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		authforce

PLIST_FILES=	bin/authforce \
		man/man1/authforce.1.gz \
		%%DATADIR%%/blank.lst \
		%%DATADIR%%/dummy.lst \
		%%DATADIR%%/password.lst \
		%%DATADIR%%/username.lst \
		%%DATADIR%%/userpass.lst

OPTIONS_DEFINE=		CURL NLS

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	curl
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_PLIST_FILES=	share/locale/nl/LC_MESSAGES/authforce.mo

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pwlistsdir = / s|/data$$||' ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^mangdir = / s|/mang$$|/man1|' ${WRKSRC}/doc/Makefile.in
	@${FIND} ${WRKSRC}/src -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^\(#include <curl/types.h>\)|/* \1 */| ; \
		 s|^\(#include <malloc.h>\)|/* \1 */|'

.include <bsd.port.mk>
