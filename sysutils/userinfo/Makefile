PORTNAME=	userinfo
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Show information about local users
WWW=		http://bjk.sourceforge.net/userinfo/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
