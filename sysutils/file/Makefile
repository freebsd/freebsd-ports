# Created by: Jason Harris <jharris@widomaker.com>
# $FreeBSD$

PORTNAME=	file
PORTVERSION=	5.38
CATEGORIES=	sysutils
MASTER_SITES=	https://astron.com/pub/file/ \
		https://www.nic.funet.fi/pub/mirrors/ftp.astron.com/pub/file/ \
		https://ftp.icm.edu.pl/packages/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Utility to determine file type

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fsect-man5
MAKE_ENV=	INSTALL_STRIP_FLAG="${STRIP}"
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/misc|$$(datadir)/${PORTNAME}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
