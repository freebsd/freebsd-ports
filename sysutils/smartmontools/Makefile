PORTNAME=	smartmontools
DISTVERSION=	7.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	samm@FreeBSD.org
COMMENT=	S.M.A.R.T. disk monitoring tools
WWW=		https://www.smartmontools.org

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib cpe

USE_RC_SUBR=	smartd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-sample \
		--with-gnupg=yes \
		--with-initscriptdir=${PREFIX}/etc/rc.d \
		--with-nvme-devicescan=yes

SUB_FILES=	pkg-message smart
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| install-initdDATA| |g' \
	    ${PATCH_WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|install-drivedbinstDATA install-examplesDATA|install-drivedbinstDATA|g' \
	    ${PATCH_WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|install-examplesSCRIPTS  install-man|install-man|g' \
	    ${PATCH_WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/smart \
		${STAGEDIR}${PREFIX}/etc/periodic/daily
	${MV} ${STAGEDIR}${DATADIR}/drivedb.h \
		${STAGEDIR}${DATADIR}/drivedb.h.sample

.include <bsd.port.mk>
