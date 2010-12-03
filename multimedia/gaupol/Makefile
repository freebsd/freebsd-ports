# New ports collection makefile for:	gaupol
# Date created:		08 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaupol
PORTVERSION=	0.17.1
CATEGORIES=	multimedia python
MASTER_SITES=	http://download.gna.org/gaupol/0.17/ \
		http://www.c-s.li/ports/

MAINTAINER=	c-s@c-s.li
COMMENT=	Subtitle editor

RUN_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet \
		py*-enchant>=1.5.1:${PORTSDIR}/textproc/py-enchant

LICENSE=	GPLv3

USE_BZIP2=	yes
USE_GNOME=	pygtk2 desktopfileutils
USE_PYTHON=	2.6+
USE_PYDISTUTILS=yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
