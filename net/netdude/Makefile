# ex:ts=8
# New ports collection makefile for: 	netdude
# Date created:			Dec 27, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	netdude
PORTVERSION=	0.4.8a
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	brenton.chang@gmail.com
COMMENT=	NETwork DUmp data Displayer and Editor for tcpdump tracefiles

LIB_DEPENDS=	netdude.0:${PORTSDIR}/net/libnetdude

USE_AUTOTOOLS=	libltdl:22 libtool:22
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${DOCSDIR}
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lltdl"
USE_GMAKE=	yes
USE_GNOME=	glib12 gtk12

MAN1=	netdude.1

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = netdude|DOC_MODULE =|' \
	${WRKSRC}/doc/netdude-manual/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|doc||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
