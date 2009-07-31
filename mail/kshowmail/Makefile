## New ports collection makefile for:	kshowmail
# Date created:			Sat Oct 18 14:01:21 CEST 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	kshowmail
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	mail kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 mail checker for KDE

LIB_DEPENDS=	mimelib.1:${PORTSDIR}/deskutils/kdepim3

USE_KDELIBS_VER=	3
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC}/admin && ${RM} -f ltmain.sh && ${CP} -f ${LTMAIN} .
	@cd ${WRKSRC}/admin && ${RM} -f libtool.m4.in && ${CP} -f ${LIBTOOL_M4} libtool.m4.in
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f admin/Makefile.common

.include <bsd.port.post.mk>
