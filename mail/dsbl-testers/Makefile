# New ports collection makefile for:	dsbl-testers
# Date created:		Fri Aug 23 09:00:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	dsbl
PORTVERSION=	0.9.4
CATEGORIES=	mail
MASTER_SITES=	http://ares.penguinhosting.net/~ian/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/
PKGNAMESUFFIX=	-testers
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Testing software configured to work with DSBL/DSBL-compliant services

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring \
		${LOCALBASE}/include/firedns.h:${PORTSDIR}/dns/firedns

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}
INSTALL_SHLIBS=	yes

MAN1=	formmailtest.1 relaytest.1 socks5test.1 \
	httptest.1 socks4test.1 spamtrap.1
MAN5=	dsbl.conf.5

# install ourselves to insure proper ownership/permissions
# as dictated by port's rules
BINARY_FILES=	formmailtest httptest relaytest socks4test socks5test \
		spamtrap
CONF_FILES=	conf/dsbl.conf

post-configure:
# let the configure script findings be used
	@${REINPLACE_CMD} -E \
		-e 's|\?=|=|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
.for file in ${BINARY_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor
.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man5
.endfor

.include <bsd.port.mk>
