# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	relaxconf
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/relaxbsd/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of text menu based utilities for configuring RelaxBSD LiveCD

BUILD_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog
RUN_DEPENDS=	cdialog:${PORTSDIR}/devel/cdialog \
		disktype:${PORTSDIR}/sysutils/disktype

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

.include <bsd.port.mk>
