# Created by: ijliao
# $FreeBSD$

PORTNAME=	clarence
PORTVERSION=	0.4.4
PORTREVISION=	8
CATEGORIES=	math python
MASTER_SITES=	# disappeared

MAINTAINER=	psh@iki.fi
COMMENT=	Programmer's calculator

DEPRECATED=		Mastersite disappeared
EXPIRATION_DATE=	2018-03-01

USES=		python:2.7 shebangfix
USE_GNOME=	pygtk2
NO_BUILD=	yes

PLIST_FILES=	bin/clarence man/man1/clarence.1.gz
SHEBANG_FILES=	clarence.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clarence.py \
		${STAGEDIR}${PREFIX}/bin/clarence
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
