# New ports collection makefile for:	kopete
# Date created:		16 Mar 2003
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kopete
PORTVERSION=	0.8.2
CATEGORIES=	net kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging system (ICQ, AIM, MSN, Jabber, Yahoo, IRC)

CONFLICTS=	kdenetwork-3.[2-].*

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in

.include <bsd.port.mk>
