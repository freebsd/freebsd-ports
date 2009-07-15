# New ports collection makefile for:   amfm
# Date created:        2009-06-21
# Whom:                sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	amfm
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://github.com/ikegam/amfm/raw/9679aa06eead7ed3571480e892f426828e17e361/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sanpei
DISTNAME=	amfm
EXTRACT_SUFX=	.c

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	THANKO USB AM/FM Radio controller

LIB_DEPENDS=	hid.0:${PORTSDIR}/devel/libhid

NO_WRKSUBDIR=   yes

.include <bsd.port.pre.mk>

EXTRACT_CMD=            ${CP}
EXTRACT_BEFORE_ARGS=    -p
EXTRACT_AFTER_ARGS=     ${WRKDIR}

.if ${OSVERSION} <= 800097
BROKEN=		does not build
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/amfm ${PREFIX}/bin/amfm

.include <bsd.port.post.mk>
