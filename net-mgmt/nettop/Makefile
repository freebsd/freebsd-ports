# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	nettop
PORTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://fossies.org/unix/privat/old/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A program which looks like top, but is for network packets

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-slang-libraries=${LOCALBASE}/lib \
		--with-slang-includes=${LOCALBASE}/include
LDFLAGS+=	-lcurses

PLIST_FILES=	bin/nettop
PORTDOCS=	README THANKS ChangeLog

DEPRECATED=	Dead upstream
EXPIRATION_DATE=2013-03-01

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '/count.*size/s/(int) //g' ${WRKSRC}/nettop.c
.if !exists(/usr/lib/libpthread.so)
	${REINPLACE_CMD} -e 's/lpthread/lc_r/g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
