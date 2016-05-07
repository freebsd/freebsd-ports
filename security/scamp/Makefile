# Created by: Gerard Seibert <gerard@seibercom.net>
# $FreeBSD$

PORTNAME=	scamp
PORTVERSION=	5.6
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gerard@seibercom.net
COMMENT=	Download & Install additional definition files for Clamav

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	bash>=4.2.42:shells/bash \
		clamav>=0.97.8:security/clamav \
		gnupg>=2.0.19:security/gnupg \
		rsync>=3.0.9:net/rsync

.if exists (${LOCALBASE}/bin/wget) && ! exists (${LOCALBASE}/bin/curl)
RUN_DEPENDS+=	wget>=1.14:ftp/wget
.else
RUN_DEPENDS+=	curl>=7.24.0_2:ftp/curl
.endif

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README CHANGE.LOG INSTALL Release.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|CLAMAV_DB=$${CLAMAV_DB:-""}|CLAMAV_DB=$${CLAMAV_DB:-\"/var/db/clamav\"}|g' ${WRKSRC}/${PORTNAME}.sh
	@${REINPLACE_CMD} -e 's|CONFIG_DIR=$${CONFIG_DIR:-"/etc/scamp"}|CONFIG_DIR=$${CONFIG_DIR:-"${ETCDIR}"}|g' ${WRKSRC}/${PORTNAME}.sh

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} scamp.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/default.sample ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
