# Ports collection makefile for:  pixilate
# Date created:			  Wed Apr 30 06:10:16 PDT 2003
# Whom:				  Barry Irwin <bvi@moria.org>
#
# $FreeBSD$

PORTNAME=	pixilate
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	winfingerprint

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Generates packets to match a list of Cisco PIX access lists

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel \
		${LOCALBASE}/share/automake14/install-sh:${PORTSDIR}/devel/automake14

WRKSRC=		${WRKDIR}/pixilate

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet-config
CFLAGS+=	`${LIBNET_CONFIG} --cflags` `${LIBNET_CONFIG} --defines`
CFLAGS+=	-I${LOCALBASE}/include
LIBS=		`${LIBNET_CONFIG} --libs`
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${LIBS}" CPPFLAGS="-I${LOCALBASE}/include"

MAN1=		pixilate.1

pre-configure:
.for i in install-sh missing mkinstalldirs
	@${LN} -sf ${LOCALBASE}/share/automake14/${i} ${WRKSRC}
.endfor
	@${RM} -f ${WRKSRC}/config.cache

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
