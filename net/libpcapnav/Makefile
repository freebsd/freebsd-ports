# New ports collection makefile for:	libpcapnav
# Date created:		2004-04-23
# Whom:			Yann Berthier <yb@sainte-barbe.org>
#
# $FreeBSD$
#

PORTNAME=	libpcapnav
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netdude

MAINTAINER=	yb@bashibuzuk.net
COMMENT=	A libpcap wrapper library

CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${DOCSDIR}
USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = pcapnav|DOC_MODULE =|' \
	${WRKSRC}/docs/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|docs||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
