# $FreeBSD$

PORTNAME=	samba-virusfilter
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://cloud.github.com/downloads/fumiyas/samba-virusfilter/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	On-access anti-virus filter for Samba

PATCH_DEPENDS=	smbclient:${PORTSDIR}/net/${SAMBA_PORT}
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/${SAMBA_PORT}:configure
RUN_DEPENDS=	ksh:${PORTSDIR}/shells/pdksh

GNU_CONFIGURE=	yes
USES=		gmake shebangfix tar:bzip2
SHEBANG_FILES=	bin/svf-notify.ksh
ALL_TARGET=	# should empty
CONFIGURE_ARGS=	--with-samba-source=`cd ${PORTSDIR}/net/${SAMBA_PORT}; ${MAKE} -VWRKSRC` \
		--with-clamd=${PREFIX}/sbin/clamd --with-savdid=${PREFIX}/bin/savdid
SAMBA_PORT?=	samba36
USE_AUTOTOOLS=	autoconf autoheader # for net/${SAMBA_PORT} configure
MAKE_ARGS=	SAMBA_DATADIR=${PREFIX}

.include <bsd.port.mk>
