# Created by: tobez@tobez.org
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	1.0.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://ftp.osuosl.org/pub/blfs/svn/l/ \
		GENTOO/distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for posting electronic mail

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

OPTIONS_DEFINE=	OPENSSL DEBUG DOCS EXAMPLES
OPTIONS_DEFAULT=OPENSSL
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug
OPENSSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
OPENSSL_USE=	openssl

GNU_CONFIGURE=	yes
# require-all-recipients (implied by enable-all) is required for Balsa
CONFIGURE_ARGS=	--enable-all --disable-isoc
INSTALL_TARGET=	install-strip
USES=		gmake libtool tar:bzip2
USE_LDCONFIG=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS Notes README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
