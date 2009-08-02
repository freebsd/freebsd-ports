# New ports collection makefile for:	opencdk
# Date created:		15 Jan 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	opencdk
PORTVERSION=	0.6.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security
MASTER_SITES=	http://josefsson.org/gnutls/releases/opencdk/
MASTER_SITE_SUBDIR=	alpha/gnutls/opencdk

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Open Crypto Development Kit

LIB_DEPENDS=	gcrypt.16:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig ltverhack
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-libgcrypt-prefix=${LOCALBASE}

DOCS=		AUTHORS NEWS README THANKS doc/opencdk-api.html

post-patch:
	@${REINPLACE_CMD} -e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.c ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tests/*.gpg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
