# ex:ts=8
# New ports collection makefile for:	pyne
# Date created:			Dec 10, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pyne
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	news python mail
MASTER_SITES=	http://www.soul-less.pwp.blueyonder.co.uk/pyne/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 offline Newsreader/Emailer

BUILD_DEPENDS=	pygtk-codegen-2.0:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
.endif

BROKEN=		"Broken pkg-plist"

USE_REINPLACE=		yes
USE_PYTHON=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ENV=		PYTHON_SITELIBDIR="${PYTHON_SITELIBDIR}"
ALL_TARGET=		default

pre-configure:
	@${REINPLACE_CMD} -e "s@[(]PREFIX[)]\/lib@(PYTHON_SITELIBDIR)@g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s@pybins=\(.*\)@pybins=\${PYTHON_VERSION}@" ${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/yencdec

.include <bsd.port.mk>
