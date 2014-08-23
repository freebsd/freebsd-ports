# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	quiterss
PORTVERSION=	0.16.1
CATEGORIES=	net
MASTER_SITES=	http://quiterss.org/files/${PORTVERSION}/
DISTNAME=	QuiteRSS-${PORTVERSION}-src

MAINTAINER=	coder@tuxfamily.org
COMMENT=	open-source cross-platform RSS/Atom news feeds reader

LICENSE=	GPLv3

USES=		desktop-file-utils pkgconfig qmake:outsource tar:bzip2
USE_SQLITE=	yes
USE_QT4=	designer moc_build linguist_build moc_build rcc_build \
		uic_build gui network phonon
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
