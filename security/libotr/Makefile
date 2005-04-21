# ex:ts=8
# New ports collection makefile for:	libotr
# Date created:				2005-03-20
# Whom:					Conor McDermottroe <ports@mcdermottroe.com>
#
# $FreeBSD$
#

PORTNAME=	libotr
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	ports@mcdermottroe.com
COMMENT=	The portable OTR Messaging Library and toolkit

LIB_DEPENDS=	gpg-error:${PORTSDIR}/security/libgpg-error \
		gcrypt:${PORTSDIR}/security/libgcrypt

USE_AUTOCONF_VER=259
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes

MAN1=		otr_toolkit.1
MLINKS=		otr_toolkit.1 otr_parse.1 \
		otr_toolkit.1 otr_sesskeys.1 \
		otr_toolkit.1 otr_mackey.1 \
		otr_toolkit.1 otr_readforge.1 \
		otr_toolkit.1 otr_modify.1 \
		otr_toolkit.1 otr_remac.1

.include <bsd.port.mk>
