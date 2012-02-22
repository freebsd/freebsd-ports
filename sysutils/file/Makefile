# New ports collection makefile for:	file
# Date created:		2001-11-10
# Whom:			Jason Harris <jharris@widomaker.com>
#
# $FreeBSD$
#

PORTNAME=	file
PORTVERSION=	5.11
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Utility to determine file type

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--enable-fsect-man5

CONFLICTS=	tct-[0-9]*

MAN1=		file.1
MAN3=		libmagic.3
MAN5=		magic.5

check regression-test test: build
	@( cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check ; )

post-patch:
	@${REINPLACE_CMD} -e 's|$(datadir)/misc|$(datadir)/${PORTNAME}|g' \
		${WRKSRC}/configure
.include <bsd.port.mk>
