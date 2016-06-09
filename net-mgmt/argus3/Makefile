# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	argus
PORTVERSION=	3.0.8.2
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generic IP network transaction auditing tool

LICENSE=	GPLv3

CONFLICTS=	argus-2* argus-sasl-2* argus-clients-2*

OPTIONS_DEFINE=	SASL
OPTIONS_DEFAULT=SASL
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl=${LOCALBASE}
SASL_VARS=	PKGNAMESUFFIX+=-sasl

USE_RC_SUBR=	argus

USES=		bison perl5
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/lib/sasl2#${LOCALBASE}/lib/sasl2#' ${WRKSRC}/argus/ArgusOutput.c

pre-install:
	@${REINPLACE_CMD} -e 's#/usr/bin/perl#${LOCALBASE}/bin/perl#' ${WRKSRC}/bin/argus-lsof
	@${REINPLACE_CMD} -e 's#/bin/bash#${LOCALBASE}/bin/bash#' ${WRKSRC}/bin/argus-vmstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus ${STAGEDIR}${PREFIX}/sbin/argus
.for i in argus-lsof argus-snmp	argus-vmstat argusbug
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${STAGEDIR}${PREFIX}/bin/$i
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/man5/argus.conf.5 ${STAGEDIR}${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/argus.8 ${STAGEDIR}${PREFIX}/man/man8/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/Archive ${STAGEDIR}${EXAMPLESDIR}/Config \
		 ${STAGEDIR}${EXAMPLESDIR}/Deployment ${STAGEDIR}${EXAMPLESDIR}/Startup \
		 ${STAGEDIR}${EXAMPLESDIR}/System
.for i in Archive/argusarchive \
	Config/argus.conf \
	Deployment/sample \
	Startup/argus Startup/README \
	System/crontab System/magic
	${INSTALL_DATA} ${WRKSRC}/support/$i ${STAGEDIR}${EXAMPLESDIR}/$i
.endfor
	${CP} ${WRKSRC}/support/Config/argus.conf ${STAGEDIR}${PREFIX}/etc/argus.conf.sample

.include <bsd.port.mk>
