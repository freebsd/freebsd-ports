# Created by: Gerard Seibert <gerard@seibercom.net>
# $FreeBSD$

PORTNAME=	scamp
PORTVERSION=	5.6
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gerard@seibercom.net
COMMENT=	Download & Install additional definition files for Clamav

LICENSE=	BSD

RUN_DEPENDS=	bash>=4.2.42:${PORTSDIR}/shells/bash \
		clamav>=0.97.8:${PORTSDIR}/security/clamav \
		gnupg>=2.0.19:${PORTSDIR}/security/gnupg \
		rsync>=3.0.9:${PORTSDIR}/net/rsync

.if exists (${LOCALBASE}/bin/wget) && ! exists (${LOCALBASE}/bin/curl)
RUN_DEPENDS+=	wget>=1.14:${PORTSDIR}/ftp/wget
.else
RUN_DEPENDS+=	curl>=7.24.0_2:${PORTSDIR}/ftp/curl
.endif

NO_BUILD=	yes
SUB_FILES=	pkg-message

MAN1=		scamp.1

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|CLAMAV_DB=$${CLAMAV_DB:-""}|CLAMAV_DB=$${CLAMAV_DB:-\"/var/db/clamav\"}|g' ${WRKSRC}/${PORTNAME}.sh
	@${REINPLACE_CMD} -e 's|CONFIG_DIR=$${CONFIG_DIR:-"/etc/scamp"}|CONFIG_DIR=$${CONFIG_DIR:-"${ETCDIR}"}|g' ${WRKSRC}/${PORTNAME}.sh

post-install:
	@if [ ! -d ${ETCDIR} ]; then \
		${MKDIR} ${ETCDIR} ; \
	fi

	@${INSTALL_DATA} ${FILESDIR}/default.sample ${ETCDIR}

	@if [ ! -f ${PREFIX}/etc/scamp/default ]; then \
		${CP} -p ${PREFIX}/etc/scamp/default.sample ${PREFIX}/etc/scamp/default ; \
	fi

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME}.sh ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} scamp.1 ${MANPREFIX}/man/man1

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README CHANGE.LOG INSTALL Release.pdf ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
