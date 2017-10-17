# $FreeBSD$

PORTNAME=	samba-virusfilter
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GHC

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	On-access anti-virus filter for Samba

BROKEN=		fails to configure with samba 4
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-11-09

PATCH_DEPENDS=	smbclient:${SAMBAPORT}
BUILD_DEPENDS=	${NONEXISTENT}:${SAMBAPORT}:configure
RUN_DEPENDS=	ksh:shells/pdksh

GNU_CONFIGURE=	yes
USES=		gmake samba:env shebangfix tar:bzip2
SHEBANG_FILES=	bin/svf-notify.ksh
USE_GITHUB=	yes
GH_ACCOUNT=	fumiyas

ALL_TARGET=	# should empty
CONFIGURE_ARGS=	--with-samba-source=`cd ${PORTSDIR}/${SAMBAPORT}; ${MAKE} -VWRKSRC` \
		--with-clamd=${PREFIX}/sbin/clamd --with-savdid=${PREFIX}/bin/savdid
USE_AUTOTOOLS=	autoconf autoheader # for ${SAMBAPORT} configure
MAKE_ARGS=	SAMBA_DATADIR=${PREFIX}

.include <bsd.port.mk>
