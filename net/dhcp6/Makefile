# New ports collection makefile for:	dhcp6
# Date created:		30 July 2004
# Whom:			sumikawa
#
# $FreeBSD$
#

PORTNAME=	dhcp6
PORTVERSION=	20040731a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/
DISTNAME=	kame-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=		KAME DHCP6 client and server

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc --with-localdbdir=/var/db
USE_REINPLACE=	yes

MAN5=		dhcp6c.conf.5 dhcp6s.conf.5
MAN8=		dhcp6c.8 dhcp6s.8 dhcp6relay.8 dhcp6sctl.8

post-patch:
.for file in ${MAN5} ${MAN8}
	${REINPLACE_CMD} -e 's|/usr/local/v6/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT ${DOCSDIR}
.endif
	${INSTALL_DATA} ${WRKSRC}/dhcp6c.conf.sample ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/dhcp6s.conf.sample ${PREFIX}/etc

.include <bsd.port.mk>
