# New ports collection makefile for: vqadmin
# Date created:		29 Mar 2001
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	vqadmin
PORTVERSION=	2.2
CATEGORIES=	mail
MASTER_SITES= 	http://www.inter7.com/vqadmin/

MAINTAINER=	nbm@FreeBSD.org

BUILD_DEPENDS= \
        ${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail
RUN_DEPENDS= \
        ${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-cgibindir=${PREFIX}/www/cgi-bin.default/

.include <bsd.port.mk>
