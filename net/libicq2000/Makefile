# New ports collection makefile for:	libicq2000
# Date created:				Sat Apr 27 10:36:05 BRT 2002
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libicq2000
PORTVERSION=	0.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++

USE_LIBTOOL=	yes

MAN1=	libicq2000-config.1

DOC_FILES=	AUTHORS COPYING ChangeLog INSTALL NEWS README THANKS \
		TODO

post-patch:
	@${PERL} -pi -e \
		's|^(headersincludedir =).+|\1\$$(includedir)/libicq2000|' \
		${WRKSRC}/libicq2000/Makefile.in

post-configure:
	@${CP} ${LOCALBASE}/bin/libtool ${WRKSRC}
	@${PERL} -pi -e 's|^(install_ltlibs=).*|\1no|' ${WRKSRC}/libtool

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
.include <bsd.port.mk>
