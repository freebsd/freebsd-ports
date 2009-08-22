# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <reso3w83@verizon.net>
#
# $FreeBSD$
#

PORTNAME=	portmanager
PORTVERSION=	0.4.1
PORTREVISION=	9
CATEGORIES=	ports-mgmt
MASTER_SITES=	SF

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	FreeBSD installed ports status and safe update utility

MAN1=		portmanager.1
MAN3=		libMG.3 MGdbAdd.3 MGdbCreate.3 MGdbDelete.3 \
		MGdbGetRecordQty.3 MGdbGoTop.3 MGdbSeek.3

GNU_CONFIGURE=		yes
USE_LDCONFIG=	yes
INSTALL_TARGET=		install info

#
# if --with-bin=something then withvar=${PREFIX} + something
# else defaults to withvar=${PREFIX} + /bin
#
# so --with-bindir=/bin will become ${PREFIX}/bin at configure
# time.
#
CONFIGURE_ARGS=	--with-prefix=${PREFIX} --with-bindir=/bin \
		--with-etcdir=/etc --with-pkgdbdir=/var/db/pkg \
		--with-portsdir=${PORTSDIR} --with-sharedir=/share/portmanager \
		--with-tempdir=/tmp

OPTIONS=	DEBUG "Enable debug support and warnings" off	\
		BUILD_DEPENDS_ARE_LEAVES "Treat build dependencies as leaves" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug=yes
.endif

.if defined(WITH_BUILD_DEPENDS_ARE_LEAVES)
CONFIGURE_ARGS+=	--with-treatBuildDependsAsLeaves=yes
.endif

# Keep this in post-configure. After run configure, this value is changed.
post-configure:
	@${REINPLACE_CMD} -e    \
		's|PACKAGE_VERSION "${PORTVERSION}"|PACKAGE_VERSION "${PORTVERSION}_${PORTREVISION}"|g' \
		${WRKSRC}/externVars.h

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
