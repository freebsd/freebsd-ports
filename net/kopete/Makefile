# New ports collection makefile for:	kopete
# Date created:		16 Mar 2003
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kopete
PORTVERSION=	0.7
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	KDE instant messaging system (ICQ, AIM, MSN, Jabber, Yahoo, IRC)

USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	LDFLAGS="-lcrypto"

pre-configure:
	${REINPLACE_CMD} -e 's|-pedantic ||g' ${WRKSRC}/configure

post-install:
	${RM} ${PREFIX}/share/locale/xx/LC_MESSAGES/kopete.mo
	-${RMDIR} ${PREFIX}/share/locale/xx/LC_MESSAGES/
	-${RMDIR} ${PREFIX}/share/locale/xx/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
