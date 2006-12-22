# ex:ts=8
# Ports collection makefile for:	nofgpg
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	nofgpg
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	http://www.cgabriel.org/download/nofgpg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	No One Fears GPG

RUN_DEPENDS=	gpgv:${PORTSDIR}/security/gnupg1 \
		${PYTHON_SITELIBDIR}/gtk-1.2/gnome/ui.py:${PORTSDIR}/x11-toolkits/py-gnome

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=		nofgpg.1
PLIST_FILES=	bin/nofgpg

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/share,${LOCALBASE}/share/gnome,g" \
		${WRKSRC}/nofgpg

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
