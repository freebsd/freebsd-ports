PORTNAME=	thewidgetfactory
PORTVERSION=	0.2.1
PORTREVISION=	7
CATEGORIES=	x11-themes
MASTER_SITES=	https://www.stellingwerff.com/TheWidgetFactory/ \
		http://vault.101011010.xyz/distfiles/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool for previewing GTK+ widgets and testing new themes

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USES=		gnome pkgconfig

PLIST_FILES=	bin/twf

post-patch:
# Fix console warnings of "GtkSpinButton: setting an adjustment with non-zero
# page size is deprecated"
	@${REINPLACE_CMD} -e 's/10, 10/10, 0/' ${WRKSRC}/src/interface.c

.include <bsd.port.mk>
