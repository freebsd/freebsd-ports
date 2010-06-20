# New ports collection makefile for:	scamp
# Date created:	31 March 2009
# Whom:	Gerard Seibert <gerard@seibercom.net>
#
# $FreeBSD$

PORTNAME=	scamp
PORTVERSION=	5.2i
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gerard@seibercom.net
COMMENT=	Download & Install additional definition files for Clamav

RUN_DEPENDS+=	bash>=4.1.5_2:${PORTSDIR}/shells/bash \
		clamav>=0.96.1:${PORTSDIR}/security/clamav \
		gnupg>=2.0.14_2:${PORTSDIR}/security/gnupg \
		rsync>=3.0.7:${PORTSDIR}/net/rsync

.if exists (${LOCALBASE}/bin/wget) && ! exists (${LOCALBASE}/bin/curl)
RUN_DEPENDS+=	wget>=1.12:${PORTSDIR}/ftp/wget
.else
RUN_DEPENDS+=	curl>=7.20.0:${PORTSDIR}/ftp/curl
.endif

NO_BUILD=	yes

SUB_FILES=	pkg-message

MAN1=		scamp.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's|CLAMAV_DB=$${CLAMAV_DB:-""}|CLAMAV_DB=$${CLAMAV_DB:-\"/var/db/clamav\"}|g' ${WRKSRC}/${PORTNAME}.sh
	@${REINPLACE_CMD} -e 's|CONFIG_DIR=$${CONFIG_DIR:-"/etc/scamp"}|CONFIG_DIR=$${CONFIG_DIR:-\"${PREFIX}/etc/scamp\"}|g' ${WRKSRC}/${PORTNAME}.sh

post-install:
	@if [ ! -d ${PREFIX}/etc/scamp ]; then \
		${MKDIR} ${PREFIX}/etc/scamp ; \
	fi

	@${INSTALL_DATA} ${FILESDIR}/default.sample ${PREFIX}/etc/scamp/
		@if [ ! -f ${PREFIX}/etc/scamp/default ]; then \
			${CP} -p ${PREFIX}/etc/scamp/default.sample \
			${PREFIX}/etc/scamp/default ; \
		fi

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME}.sh ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} scamp.1 ${MANPREFIX}/man/man1

.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README CHANGE.LOG INSTALL Release.html ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
