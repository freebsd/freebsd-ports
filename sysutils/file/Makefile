# Created by: Jason Harris <jharris@widomaker.com>
# $FreeBSD$

PORTNAME=	file
PORTVERSION=	5.29
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	jharris@widomaker.com
COMMENT=	Utility to determine file type

LICENSE=	BSD2CLAUSE

USES=		libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-fsect-man5
MAKE_ENV+=	INSTALL_STRIP_FLAG="${STRIP}"

CONFLICTS=	tct-[0-9]*

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} check

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/misc|$$(datadir)/${PORTNAME}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
