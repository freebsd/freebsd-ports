# Created by: clement
# $FreeBSD$

PORTNAME=	pwauth
PORTVERSION=	2.3.10
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://www.unixpapa.com/software/

MAINTAINER=	eg@fbsd.lt
COMMENT=	A Unix Web Authenticator

PLIST_FILES=	bin/pwauth bin/checkfaillog

ALL_TARGET=	pwauth checkfaillog
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LIB="-lcrypt -lpam"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-utmpx
.endif

WWWUID!=	${ID} -u ${WWWOWN}
MINUID?=	1000

post-patch:
	@${REINPLACE_CMD} "s/%%UIDS%%/${WWWUID}/ ; \
		s/%%MINUID%%/${MINUID}/" ${WRKSRC}/config.h

do-install:
	-@${MKDIR} ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/pwauth ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/checkfaillog ${PREFIX}/bin
	@${CHMOD} u=rxs ${PREFIX}/bin/pwauth

.include <bsd.port.post.mk>
