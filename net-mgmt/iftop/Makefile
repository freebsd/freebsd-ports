# New ports collection makefile for: 	iftop
# Date created:       			24 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	iftop
PORTVERSION=	0.16
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.ex-parrot.com/~pdw/iftop/download/ \
		http://voodoo.oberon.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network utility for real-time bandwidth usage information

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_REINPLACE=	yes

MAN8=		iftop.8

PORTDOCS=	README
PLIST_FILES=	bin/iftop

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		 ${WRKSRC}/configure

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MANPREFIX}/man/man8

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
