PORTNAME=	isic
PORTVERSION=	0.07
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ISIC%20v${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	IP Stack Integrity Checker
WWW=		https://sourceforge.net/projects/isic/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libnet.so:net/libnet

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		tar:tgz

.include <bsd.port.mk>
