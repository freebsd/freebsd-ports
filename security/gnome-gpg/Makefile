# New ports collection makefile for:	gnome-gpg
# Date created:		2006-09-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/security/gnome-gpg/Makefile,v 1.1 2006/09/02 15:20:58 ahze Exp $

PORTNAME=	gnome-gpg
PORTVERSION=	0.5.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Simple commandline wrapper around gpg for gnome-keyring

BUILD_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1
LIB_DEPENDS=	gnome-keyring.0:${PORTSDIR}/security/gnome-keyring
RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libgnomeui
CONFIGURE_ENV=	set_more_warnings="no"

PLIST_FILES=	bin/gnome-gpg
MAN1=		gnome-gpg.1

.include <bsd.port.mk>
