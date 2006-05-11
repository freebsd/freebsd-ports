# New ports collection makefile for:	libicq2000
# Date created:				Sat Apr 27 10:36:05 BRT 2002
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libicq2000
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An opensource C++ library to support icq2000/2001 protocol

LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-static
INSTALLS_SHLIB=	yes

MAN1=	libicq2000-config.1

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS \
		TODO

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|^(headersincludedir =).+|\1\$$(includedir)/libicq2000|' \
		${WRKSRC}/libicq2000/Makefile.in
	@${REINPLACE_CMD} -E -e 's|^(pkgincludedir.+)/@PACKAGE@|\1|' \
		${WRKSRC}/libicq2000-config.in

pre-configure:
	@${CP} ${LTMAIN} ${WRKSRC}

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
