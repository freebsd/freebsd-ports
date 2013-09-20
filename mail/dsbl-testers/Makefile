# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	dsbl-testers
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Testing software configured to work with DSBL/DSBL-compliant services

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring \
		${LOCALBASE}/include/firedns.h:${PORTSDIR}/dns/firedns

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=	auth-relaytest.1 formmailtest.1 getcookie.1 httptest.1 \
	relaytest.1 socks4test.1 socks5test.1 spamtrap.1
MAN5=	dsbl.conf.5

NO_STAGE=	yes
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
		${INSTALL_PROGRAM} ${BINARY_FILES} ${PREFIX}/bin && \
		${INSTALL_DATA} ${LOCAL_CONF_FILES} ${PREFIX}/etc
	cd ${WRKSRC}/man && \
		${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1 && \
		${INSTALL_MAN} ${MAN5} ${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
