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

USES=		tar:bzip2
USE_XORG=	xpm
USE_AUTOTOOLS=	autoheader
CONFIGURE_ARGS=	--program-prefix=""

PLIST_FILES=	"@(,kmem,2555) bin/wmupmon" man/man1/wmupmon.1.gz

post-patch:
	@${REINPLACE_CMD} '/SETGID_FLAGS=/d' ${WRKSRC}/configure.ac
	@${TOUCH} -mr ${WRKSRC}/configure.ac.bak ${WRKSRC}/configure.ac

.include <bsd.port.mk>
