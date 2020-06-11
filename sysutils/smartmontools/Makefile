# Created by: Eduard Martinescu
# $FreeBSD$

PORTNAME=	smartmontools
PORTVERSION=	7.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	samm@FreeBSD.org
COMMENT=	S.M.A.R.T. disk monitoring tools

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias compiler:c++11-lib shebangfix
USE_RC_SUBR=	smartd

SHEBANG_FILES=	examplescripts/Example5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-sample \
		--with-gnupg=no \
		--with-initscriptdir=${PREFIX}/etc/rc.d \
		--with-nvme-devicescan=yes \
		--with-update-smart-drivedb=no

SUB_FILES=	pkg-message smart

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| install-initdDATA| |' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/smart \
		${STAGEDIR}${PREFIX}/etc/periodic/daily

.include <bsd.port.mk>
