# $FreeBSD$

PORTNAME=	dsbbatmon
PORTVERSION=	0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	GTK+ battery monitor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig tar:tgz
USE_GNOME=	gtk20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_MAKE_ARGS_OFF=	-DWITHOUT_GETTEXT

.include <bsd.port.mk>
