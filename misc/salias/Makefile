# Created by: ijliao
# $FreeBSD$

PORTNAME=	salias
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/C%20${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLI tool to alias arguments of other programs

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USES=		pkgconfig
USE_BZIP2=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes

MAN1=		salias.1
DOCS=		NEWS README

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
