# New ports collection makefile for:	openr2
# Date created:				28 Jun 2012
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openr2
PORTVERSION=	1.3.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	MFC/R2 call setup library

BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:${PORTSDIR}/misc/dahdi

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
USE_LDCONFIG=	yes

MAN5=		r2test.conf.5
MAN8=		r2test.8

CONF_FILES=	etc/r2proto.conf etc/r2test.conf

post-install:
.for f in ${CONF_FILES}
	[ -e ${PREFIX}/$f ] || ${INSTALL_DATA} ${PREFIX}/$f-dist ${PREFIX}/$f
.endfor

.include <bsd.port.mk>
