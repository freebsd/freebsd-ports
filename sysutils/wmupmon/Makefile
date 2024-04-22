PORTNAME=	wmupmon
PORTVERSION=	0.1.3
PORTREVISION=	6
CATEGORIES=	sysutils windowmaker
# URL link over http://freecode.com/projects/wmupmon
MASTER_SITES=	http://j-z-s.com/projects/downloads/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Uptime showing dockapp with a similar look to wmcpuload
WWW=		http://freecode.com/projects/wmupmon

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES=		autoreconf tar:bzip2 xorg
USE_XORG=	xpm
CONFIGURE_ARGS=	--program-prefix=""

PLIST_FILES=	"@(,kmem,2555) bin/wmupmon" share/man/man1/wmupmon.1.gz

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
