# Created by: Denis Barov
# $FreeBSD$

PORTNAME=	smbnetfs
PORTVERSION=	0.6.1
CATEGORIES=	sysutils net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SMBNetFS-${PORTVERSION}
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Mount smb shares (Fuse filesystem)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS LIBSECRET

LIBSECRET_DESC=	Use libsecret to store credentials
LIBSECRET_CONFIGURE_WITH=	libsecret
LIBSECRET_LIB_DEPENDS=	libsecret-*.so:security/libsecret

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

USES=		fuse iconv pkgconfig samba:lib tar:bzip2
USE_GNOME=	glib20:build

GNU_CONFIGURE=	yes
# A hack to disable gratuitous linking with -lglib-2.0
CONFIGURE_ENV+=	GLIB_LIBS=-L/var/empty
CFLAGS+=	-I${SAMBAINCLUDES}
LDFLAGS+=	-L${SAMBALIBS}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ICONV_LIB} == ""
CONFIGURE_ENV+=	ac_cv_lib_iconv_iconv_open=yes
CONFIGURE_ARGS+=--with-libiconv=native
.endif

.include <bsd.port.post.mk>
