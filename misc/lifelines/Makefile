# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	lifelines
PORTVERSION=	3.0.51
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20beta%20versions/${PORTVERSION}

MAINTAINER=	matt@gsicomp.on.ca
COMMENT=	An advanced genealogical system

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		bison iconv

MAN1=		btedit.1 dbverify.1 llines.1

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,ncursesw/curses.h,curses.h,' \
		${WRKSRC}/src/hdrs/mycurses.h
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's,install-data-am: install-docDATA,install-data-am:,' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,install-data-am: install-dist_pkgdataDATA install-docDATA install-man,install-data-am: install-dist_pkgdataDATA,' \
		${WRKSRC}/docs/Makefile.in
.endif

post-install:
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/${file} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
