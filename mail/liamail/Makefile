# ex:ts=8
# Ports collection makefile for:	liamail
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liamail
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@freebsd.org
COMMENT=	A graphical mail client

PLIST_FILES=	bin/liamail
USE_REINPLACE=	yes
USE_QT_VER=	2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}"
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/qt.so/qt2.so/g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/-lqt/-lqt2/g" ${WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
