# ex:ts=8
# Ports collection makefile for:  dict
# Date created:			  19 February 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	dict
PORTVERSION=	1.9.11
PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dict
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	dd@FreeBSD.org
COMMENT=	Dictionary Server Protocol (RFC2229) client

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl

USE_BISON=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
ALL_TARGET=	dict
INSTALL_TARGET=	install.dict
MAN1=		dict.1 dictl.1

post-patch:
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/dict.1

post-install:
	if [ ! -f ${PREFIX}/etc/dict.conf ]; then \
		${INSTALL_DATA} ${FILESDIR}/dict.conf ${PREFIX}/etc; \
	fi

.include <bsd.port.mk>
