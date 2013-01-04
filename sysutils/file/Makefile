# Created by: Jason Harris <jharris@widomaker.com>
# $FreeBSD$

PORTNAME=	file
PORTVERSION=	5.12
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.astron.com/pub/file/ \
		ftp://ftp.fu-berlin.de/unix/tools/file/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Utility to determine file type

LICENSE=	BSD

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--enable-fsect-man5

CONFLICTS=	tct-[0-9]*

MAN1=		file.1
MAN3=		libmagic.3
MAN5=		magic.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
CONFIGURE_ENV+=	gl_cv_cc_visibility=no
.endif

check regression-test test: build
	@( cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check ; )

post-patch:
	@${REINPLACE_CMD} -e 's|$(datadir)/misc|$(datadir)/${PORTNAME}|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
