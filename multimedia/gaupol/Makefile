# New ports collection makefile for:	gaupol
# Date created:		08 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaupol
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/gaupol/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=1.5.1:${PORTSDIR}/textproc/py-enchant \
		${PYTHON_SITELIBDIR}/chardet/__init__.py:${PORTSDIR}/textproc/py-chardet \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	pygtk2
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
MAN1=	${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g;s|share/gaupol|${DATADIR_REL}|g;\
		/data_dir =/s|=.*|= "${DATADIR}"|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
