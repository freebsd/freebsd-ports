# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	dsbl-testers
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Testing software for DSBL/DSBL-compliant services

BROKEN=		unfetchable

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:misc/firestring \
		${LOCALBASE}/include/firedns.h:dns/firedns

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_JOBS_UNSAFE=	yes

MPG1=	auth-relaytest.1 formmailtest.1 getcookie.1 httptest.1 \
	relaytest.1 socks4test.1 socks5test.1 spamtrap.1
MPG5=	dsbl.conf.5

post-patch:
	@-${RM} ${WRKSRC}/firemake/*.orig
	@-${RM} ${WRKSRC}/firedns/firemake/*.orig
	@-${RM} ${WRKSRC}/firestring/firemake/*.orig

# install ourselves to insure proper ownership/permissions
# as dictated by port's rules
BINARY_FILES=	auth-relaytest formmailtest httptest relaytest \
		getcookie socks4test socks5test spamtrap
LOCAL_CONF_FILES=	conf/dsbl.conf

do-install:
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${BINARY_FILES} \
			${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_DATA} ${LOCAL_CONF_FILES} ${STAGEDIR}${PREFIX}/etc
	cd ${WRKSRC}/man && \
		${INSTALL_MAN} ${MPG1} ${STAGEDIR}${MAN1PREFIX}/man/man1 && \
		${INSTALL_MAN} ${MPG5} ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
