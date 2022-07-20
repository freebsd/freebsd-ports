PORTNAME=	swapd
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rkeene.org/files/oss/swapd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon that watches free memory and manages swap files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libstatgrab.so:devel/libstatgrab

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

USE_RC_SUBR=	swapd

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
.for f in swapd_swapon swapd_swapoff
	${INSTALL_SCRIPT} ${FILESDIR}/${f} ${STAGEDIR}${PREFIX}/sbin
.endfor

.include <bsd.port.mk>
