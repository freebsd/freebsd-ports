# New ports collection makefile for:	nettop
# Date created:				21 April 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nettop
PORTVERSION=	0.2.3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://srparish.net/scripts/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A program which looks like top, but is for network packets

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-slang-libraries=${LOCALBASE}/lib \
		--with-slang-includes=${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-lcurses"

PLIST_FILES=	bin/nettop
PORTDOCS=	README THANKS ChangeLog

post-patch:
.if !exists(/usr/lib/libpthread.so)
	${REINPLACE_CMD} -e 's/lpthread/lc_r/g' ${WRKSRC}/${CONFIGURE_SCRIPT}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
