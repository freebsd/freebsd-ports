# Created by: Adrian Wontroba <aw1@stade.co.uk>
# $FreeBSD$

PORTNAME=	xlogmaster
PORTVERSION=	1.6.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick & easy monitoring of logfiles and devices

USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		xlogmaster.1
INFO=		xlogmaster

CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|getopt_long_only|getopt_long|g' ${WRKSRC}/src/xlogmaster.cc

post-install:
	${INSTALL_DATA} ${FILESDIR}/xlogmasterrc ${PREFIX}/etc/xlogmaster

.include <bsd.port.mk>
