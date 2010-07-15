# New ports collection makefile for:	gaupol
# Date created:		08 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaupol
PORTVERSION=	0.17
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/gaupol/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor

RUN_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		py*-chardet>=0:${PORTSDIR}/textproc/py-chardet \
		py*-enchant>=1.5.1:${PORTSDIR}/textproc/py-enchant

USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g' ${WRKSRC}/setup.py

.include <bsd.port.mk>
