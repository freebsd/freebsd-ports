# New ports collection makefile for:	howl
# Date created:			21 July 2003
# Whom:				David Magda <dmagda+howl@ee.ryerson.ca>
# $FreeBSD$
#

PORTNAME=	howl
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES?=	net devel
MASTER_SITES=	http://www.porchdogsoft.com/download/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Zeroconf/Bonjour(tm) implementation

USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
USE_REINPLACE=	yes

INSTALLS_SHLIB=	yes
MAN8=		mDNSResponder.8

PLIST_SUB=	VERSION="${PORTVERSION}"
RC_SCRIPTS_SUB=	RC_SUBR=${RC_SUBR} PREFIX=${PREFIX}

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${PTHREAD_LIBS}"

CONFLICTS=	avahi-[0-9]*

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/mdnsresponder.sh > ${WRKSRC}/mdnsresponder.sh

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mdnsresponder.sh \
		${PREFIX}/etc/rc.d/mdnsresponder.sh

.include <bsd.port.mk>
