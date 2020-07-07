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

PATCH_SITES=	https://gitweb.gentoo.org/repo/gentoo.git/plain/net-libs/libesmtp/files/ \
		https://raw.githubusercontent.com/gentoo/gentoo/master/net-libs/libesmtp/files/
PATCHFILES=	libesmtp-1.0.6-openssl-1.1-api-compatibility.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for posting electronic mail

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BROKEN_SSL=	openssl

USES=		autoreconf gmake libtool tar:bzip2
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

.include <bsd.port.mk>
