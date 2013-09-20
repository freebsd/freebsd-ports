# Created by: Stefan Walter <swalter@lettermax.de>
# $FreeBSD$

PORTNAME=	vifm
PORTVERSION=	0.7.4b
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	kaspars@bankovskis.lv
COMMENT=	Ncurses based file manager with vi like keybindings

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--without-gtk
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

MAN1=		vifm.1 \
		vifm-pause.1 \
		vifmrc-converter.1
PLIST_FILES=	bin/vifm \
		bin/vifmrc-converter \
		bin/vifm-pause \
		%%DATADIR%%/vifm-help.txt \
		%%DATADIR%%/vifmrc
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.mk>
