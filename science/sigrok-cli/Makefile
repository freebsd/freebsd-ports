PORTNAME=	sigrok-cli
PORTVERSION=	0.7.2
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/sigrok-cli/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, CLI client

LICENSE=	GPLv3

LIB_DEPENDS=	libserialport.so:devel/libserialport \
		libsigrok.so:devel/libsigrok \
		libsigrokdecode.so:devel/libsigrokdecode

USES=		desktop-file-utils gettext-runtime gmake gnome libtool pathfix \
		pkgconfig

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/sigrok-cli \
		man/man1/sigrok-cli.1.gz \
		share/applications/org.sigrok.sigrok-cli.desktop \
		share/icons/hicolor/scalable/apps/sigrok-cli.svg

.include <bsd.port.mk>
