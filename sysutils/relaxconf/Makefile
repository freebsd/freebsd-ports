# New ports collection makefile for:	RelaxBSD
# Date created:		2005-10-12
# Whom:		 	Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	relaxconf
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/relaxbsd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of text menu based utilities for configuring RelaxBSD LiveCD

BUILD_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog
RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog \
		disktype:${PORTSDIR}/sysutils/disktype

GNU_CONFIGURE=	yes

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.include <bsd.port.mk>
