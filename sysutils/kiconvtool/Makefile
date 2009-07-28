# New ports collection makefile for:	kiconvtool
# Date created:		25 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kiconvtool
PORTVERSION=	0.93
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	amdmi3

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tool to preload kernel iconv charset tables

PLIST_FILES=	sbin/kiconvtool etc/rc.d/kiconv

MAN8=		kiconvtool.8

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/kiconv.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kiconvtool ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/kiconv.sh ${PREFIX}/etc/rc.d/kiconv
	${INSTALL_MAN} ${WRKSRC}/kiconvtool.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
