PORTNAME=	wmdiskmon
PORTVERSION=	0.0.2
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Disk usage monitor dockapp
WWW=		http://tnemeth.free.fr/projets/dockapps.html

USES=		xorg
USE_XORG=	x11 xpm
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=""

PLIST_FILES=	"@(,kmem,2555) bin/${PORTNAME}" share/man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure

.include <bsd.port.mk>
