PORTNAME=	dictd
PORTVERSION=	1.13.3
CATEGORIES+=	net textproc
MASTER_SITES=	SF/dict/dictd/dictd-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Dict protocol (RFC 2229) server
WWW=		https://www.dict.org/ \
		https://sourceforge.net/projects/dict/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmaa.so:devel/libmaa

USES=		bison gmake libtool:build localbase

ALL_TARGET=	dictd dictzip
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install.dictd install.dictzip

SUB_FILES=	dictd.conf pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}
USE_RC_SUBR=	dictd

post-install:
	${INSTALL_DATA} ${WRKDIR}/dictd.conf ${STAGEDIR}${PREFIX}/etc/dictd.conf.sample

.include <bsd.port.mk>
