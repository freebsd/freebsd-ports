# $FreeBSD$

PORTNAME=	samba-virusfilter
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GHC

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	On-access anti-virus filter for Samba

PATCH_DEPENDS=	smbclient:net/${SAMBA_PORT}
BUILD_DEPENDS=	${NONEXISTENT}:net/${SAMBA_PORT}:configure
RUN_DEPENDS=	ksh:shells/pdksh

GNU_CONFIGURE=	yes
USES=		gmake shebangfix tar:bzip2
SHEBANG_FILES=	bin/svf-notify.ksh
USE_GITHUB=	yes
GH_ACCOUNT=	fumiyas

ALL_TARGET=	# should empty
CONFIGURE_ARGS=	--with-samba-source=`cd ${PORTSDIR}/net/${SAMBA_PORT}; ${MAKE} -VWRKSRC` \
		--with-clamd=${PREFIX}/sbin/clamd --with-savdid=${PREFIX}/bin/savdid
SAMBA_PORT?=	samba36
USE_AUTOTOOLS=	autoconf autoheader # for net/${SAMBA_PORT} configure
MAKE_ARGS=	SAMBA_DATADIR=${PREFIX}

.include <bsd.port.mk>
