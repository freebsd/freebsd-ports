# Created by: Alex Varju <varju@webct.com>
# $FreeBSD$

# "?=" and "+=" are for including this Makefile from japanese/jpilot"

PORTNAME=	jpilot
PORTVERSION=	1.8.2
PORTREVISION=	5
CATEGORIES+=	palm comms
MASTER_SITES=	http://www.mirrorservice.org/sites/master.us.finkmirrors.net/distfiles/ \
		http://jpilot.org/

MAINTAINER?=	samm@os2.kiev.ua
COMMENT=	Desktop Organizer Software for the Palm Pilot

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpisock.so:palm/pilot-link

USE_GCC=	any
USES=		pkgconfig gmake libtool
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}
USE_GNOME+=	gtk20 intltool
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=		gettext-tools

post-build:
	cd ${WRKSRC}/docs && ${MAKE_CMD}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-dial.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-dump.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-sync.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/empty/*.pdb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jpilotrc.* ${STAGEDIR}${DATADIR}
.for ext in html png jpg
	${INSTALL_DATA} ${WRKSRC}/docs/*.${ext} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in AUTHORS BUGS ChangeLog INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/README ${STAGEDIR}${DOCSDIR}/README.icons

.include <bsd.port.mk>
