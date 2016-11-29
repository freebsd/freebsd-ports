# Created by: tobez@tobez.org
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	1.0.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://ftp.osuosl.org/pub/blfs/svn/l/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for posting electronic mail

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
# require-all-recipients (implied by enable-all) is required for Balsa
CONFIGURE_ARGS=	--enable-all --disable-isoc
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENSSL DEBUG DOCS EXAMPLES
OPTIONS_DEFAULT=OPENSSL
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debug
OPENSSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
OPENSSL_USES=		ssl

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS Notes README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
