# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	sigrok-cli
PORTVERSION=	0.4.0
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/sigrok-cli/

MAINTAINER=	uffe@uffe.org
COMMENT=	Framework for hardware logic analyzers, CLI client

LICENSE=	GPLv3

LIB_DEPENDS=	libsigrok.so:${PORTSDIR}/devel/libsigrok \
		libsigrokdecode.so:${PORTSDIR}/devel/libsigrokdecode

PLIST_FILES=	bin/sigrok-cli man/man1/sigrok-cli.1.gz
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig pathfix
USE_GNOME=	gtk20
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
