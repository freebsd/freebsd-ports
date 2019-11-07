# Created by: pat
# $FreeBSD$

PORTNAME=	wmupmon
PORTVERSION=	0.1.3
PORTREVISION=	5
CATEGORIES=	sysutils windowmaker
# URL link over http://freecode.com/projects/wmupmon
MASTER_SITES=	http://j-z-s.com/projects/downloads/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Uptime showing dockapp with a similar look to wmcpuload

GNU_CONFIGURE=	yes
USES=		autoreconf tar:bzip2 xorg
USE_XORG=	xpm
CONFIGURE_ARGS=	--program-prefix=""

PLIST_FILES=	"@(,kmem,2555) bin/wmupmon" man/man1/wmupmon.1.gz

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
