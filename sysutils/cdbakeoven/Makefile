# New ports collection makefile for:	cdbakeoven
# Date created:		19 September 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	cdbakeoven
PORTVERSION=	1.8.9
PORTREVISION=	4
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	michaelnottebrock@gmx.net
COMMENT=	KDE frontend for cdrecord and mkisofs/mkhybrid

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs \
		mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
