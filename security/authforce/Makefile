# Created by: ache
# $FreeBSD$

PORTNAME=	authforce
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	security www
MASTER_SITES=	http://cloud.github.com/downloads/zlandau/authforce/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP authentication brute forcer

LICENSE=	GPLv2

OPTIONS_DEFINE=	CURL NLS

USES=		ncurses
#USE_READLINE=	yes
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
NO_CCACHE=	yes

MANCOMPRESSED=	yes
MAN1=		authforce.1
INFO=		authforce

PLIST_FILES=	bin/authforce \
		%%DATADIR%%/blank.lst \
		%%DATADIR%%/dummy.lst \
		%%DATADIR%%/password.lst \
		%%DATADIR%%/username.lst \
		%%DATADIR%%/userpass.lst

PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=	--without-curl
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_FILES+=	share/locale/nl/LC_MESSAGES/authforce.mo
CONFIGURE_ENV+=	CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^pwlistsdir = / s|/data$$||' ${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^mangdir = / s|/mang$$|/man1|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		'/<curl\/types.h>/d' ${WRKSRC}/src/http.c
.for i in extract.c methods.c misc.c
	@${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|' ${WRKSRC}/src/${i}
.endfor

.include <bsd.port.mk>
