# New ports collection makefile for:	gpass
# Date created:		2006-07-24
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	gpass
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	http://projects.netlab.jp/gpass/release/

MAINTAINER=	ports@c0decafe.net
COMMENT=	A password manager for GNOME2

LIB_DEPENDS=	mcrypt:${PORTSDIR}/security/mcrypt \
		mhash:${PORTSDIR}/security/mhash

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -export-dynamic"
USE_GMAKE=	yes

MAN1=	gpass.1 gpass.ja.1 gpass-convert.1 gpass-convert.ja.1

USE_GNOME=	gtk20 libgnomeui intltool libglade2
GCONF_SCHEMAS=	gpass.schemas

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
