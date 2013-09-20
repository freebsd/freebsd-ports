# Created by: Keith Gaughan <k@stereochro.me>
# $FreeBSD$

PORTNAME=	greyfix
PORTVERSION=	0.3.9
CATEGORIES=	mail
MASTER_SITES=	http://www.kim-minh.com/pub/greyfix/

MAINTAINER=	k@stereochro.me
COMMENT=	A greylisting policy daemon for Postfix

SUB_FILES=	pkg-message

USE_BDB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-berkeleydb-libdir=${BDB_LIB_DIR} \
		--with-berkeleydb-includedir=${BDB_INCLUDE_DIR} \
		--localstatedir=/var

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|-ldb|-l${BDB_LIB_NAME}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|$$(localstatedir)/lib|$$(localstatedir)/db|' ${WRKSRC}/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/greyfix ${PREFIX}/sbin
	@${INSTALL} -o nobody -m 700 -d /var/db/greyfix

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
