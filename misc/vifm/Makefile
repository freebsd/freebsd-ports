# Created by: Stefan Walter <swalter@lettermax.de>
# $FreeBSD$

PORTNAME=	vifm
PORTVERSION=	0.7.7
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	kaspars@bankovskis.lv
COMMENT=	Ncurses based file manager with vi like keybindings

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses tar:bzip2
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--without-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

PLIST_FILES=	bin/vifm \
		bin/vifmrc-converter \
		bin/vifm-pause \
		%%DATADIR%%/vifm-help.txt \
		%%DATADIR%%/vifmrc \
		share/applications/vifm.desktop \
		share/pixmaps/vifm.png \
		man/man1/vifm-pause.1.gz \
		man/man1/vifm.1.gz \
		man/man1/vifmrc-converter.1.gz
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
