# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <reso3w83@verizon.net>
#
# $FreeBSD$
#

PORTNAME=	portmanager
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://portmanager.sunsite.dk/distfiles/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	portmanager

MAINTAINER=	ringworm01@gmail.com
COMMENT=	FreeBSD installed ports status and safe update utility

MAN1=		portmanager.1
MAN3=		libMG.3 MGdbAdd.3 MGdbCreate.3 MGdbDelete.3 \
		MGdbGetRecordQty.3 MGdbGoTop.3 MGdbSeek.3

GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALL_TARGET=		install info

#
# if --with-bin=something then withvar=${PREFIX} + something
# else defaults to withvar=${PREFIX} + /bin
#
# so --with-bindir=/bin will become ${PREFIX}/bin at configure
# time.
#
CONFIGURE_ARGS=	--with-prefix=${PREFIX} --with-bindir=/bin \
		--with-etcdir=/etc/portmanager --with-pkgdbdir=/var/db/pkg \
		--with-portsdir=${PORTSDIR} --with-sharedir=/share/portmanager \
		--with-tempdir=/tmp

OPTIONS=	DEBUG	"Enables debug support and all compile warning"	off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug=yes
.endif

# Keep this in post-configure. After run configure, he change this value.
post-configure:
	@${REINPLACE_CMD} -e    \
		's|PACKAGE_VERSION "${PORTVERSION}"|PACKAGE_VERSION "${PORTVERSION}_${PORTREVISION}"|g' \
		${WRKSRC}/externVars.h

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
