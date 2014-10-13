# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	lifelines
PORTVERSION=	3.0.62
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	matt@gsicomp.on.ca
COMMENT=	Advanced genealogical system

GNU_CONFIGURE=	yes
USES=		bison iconv tar:bzip2

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
CONFIGURE_ARGS+=--disable-nls
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

.include <bsd.port.mk>
