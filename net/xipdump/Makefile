# New ports collection makefile for:	xipdump
# Date created:				17 Jun 2001
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	xipdump
PORTVERSION=	1.5.4
CATEGORIES=	net
MASTER_SITES=	http://www.epita.fr/~lse/projects/xipdump/
EXTRACT_SUFX=	.tgz

MAINTAINER=	umeno@rr.iij4u.or.jp

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

USE_X_PREFIX=	yes
LIBNET_CONFIG=	${LOCALBASE}/bin/libnet-config
CFLAGS+=	`${LIBNET_CONFIG} --cflags` `${LIBNET_CONFIG} --defines`
CFLAGS+=	-I${LOCALBASE}/include
LIBS=		`${LIBNET_CONFIG} --libs`
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${LIBS}"

PLIST=	${WRKDIR}/PLIST

MAN8=	xipdump.8

post-build:
	@${CP} ${PKGDIR}/pkg-plist ${PLIST}
	@(cd ${WRKSRC}/data; find pkc pkt ! -type d | \
		${SED} -e 's|^|share/xipdump/|' >> ${PLIST})
	@${ECHO} "@dirrm share/xipdump/pkt" >> ${PLIST}
	@${ECHO} "@dirrm share/xipdump/pkc" >> ${PLIST}
	@${ECHO} "@dirrm share/xipdump" >> ${PLIST}

.include <bsd.port.mk>
