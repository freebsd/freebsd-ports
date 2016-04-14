# Created by: Marcel Kaiser <mk@nic-nac-project.org>
# $FreeBSD$

PORTNAME=	dsbmc
PORTVERSION=	0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	GTK+ client for DSBMD that lets you mount media, and more

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/libexec/dsbmd:sysutils/dsbmd

USES=		tar:tgz pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_MAKE_ARGS_OFF=	-DWITHOUT_GETTEXT

.include <bsd.port.mk>
