# ex:ts=8
# Ports collection makefile for:  dict
# Date created:			  19 February 1998
# Whom:				  Josh Gilliam <josh@quick.net>
#
# $FreeBSD$
#

PORTNAME=	dict
PORTVERSION=	1.11.1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}d-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Dictionary Server Protocol (RFC2229) client

LIB_DEPENDS=	maa.1:${PORTSDIR}/devel/libmaa

USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-local-zlib --with-cflags="${CFLAGS}" \
		--with-etcdir=${PREFIX}/etc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
ALL_TARGET=	dict
INSTALL_TARGET=	install.dict
MAN1=		dict.1 dictl.1

post-patch:
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/dict.1.in

post-configure:
	${REINPLACE_CMD} -e 's|^        mkdir|	mkdir|g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${FILESDIR}/dict.conf ${PREFIX}/etc/dict.conf.sample
	if [ ! -f ${PREFIX}/etc/dict.conf ]; then \
		${CP} -p ${PREFIX}/etc/dict.conf.sample ${PREFIX}/etc/dict.conf; \
	fi

.include <bsd.port.mk>
