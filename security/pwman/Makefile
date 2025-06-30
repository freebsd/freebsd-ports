PORTNAME=	pwman
DISTVERSION=	0.4.5
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console password management application based on gpg(me)
WWW=		https://pwman.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gpgv:security/gnupg1

USES=		gnome ncurses
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	curses_loc=${NCURSESBASE}

PORTDOCS=	AUTHORS ChangeLog README TODO
PLIST_FILES=	bin/convert_pwdb bin/pwdb2csv bin/pwman share/man/man1/pwman.1.gz

CFLAGS+=	-Wno-error=return-type

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/src/options.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
