# Created by: Matt Emmerton <matt@gsicomp.on.ca>
# $FreeBSD$

PORTNAME=	lifelines
PORTVERSION=	3.0.62
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	matt@gsicomp.on.ca
COMMENT=	Advanced genealogical system

LICENSE=	MIT

USES=		bison iconv tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-patch:
	@${REINPLACE_CMD} -e 's,ncursesw/curses\.h,curses.h,' \
		${WRKSRC}/src/hdrs/mycurses.h

.include <bsd.port.mk>
