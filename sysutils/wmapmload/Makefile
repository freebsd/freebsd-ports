PORTNAME=	wmapmload
PORTVERSION=	0.3.4
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://tnemeth.free.fr/projets/programmes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	APM battery status monitor dockapp with a similar look to wmcpuload
WWW=		http://tnemeth.free.fr/projets/dockapps.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386
USES=		xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=""

.include <bsd.port.mk>
