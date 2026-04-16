PORTNAME=	argus
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	net-mgmt security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generic IP network transaction auditing tool
WWW=		https://openargus.org/

LICENSE=	GPLv3

USES=		bison perl5
USE_GITHUB=	yes
GH_ACCOUNT=	openargus
USE_RC_SUBR=	argus

GNU_CONFIGURE=	yes

CONFLICTS=	argus-*

OPTIONS_DEFINE=	SASL EXAMPLES
OPTIONS_DEFAULT=SASL

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl=${LOCALBASE}
SASL_VAR=		PKGNAMESUFFIX=-sasl

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/lib/sasl2#${LOCALBASE}/lib/sasl2#' ${WRKSRC}/argus/ArgusOutput.c
	@${REINPLACE_CMD} -e 's#tts->tv_nsec >#tts->tv_nsec >=#' ${WRKSRC}/argus/ArgusSource.c

pre-install:
	@${REINPLACE_CMD} -e 's#/usr/bin/perl#${LOCALBASE}/bin/perl#' ${WRKSRC}/bin/argus-lsof
	@${REINPLACE_CMD} -e 's#/bin/bash#${LOCALBASE}/bin/bash#' ${WRKSRC}/bin/argus-vmstat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus ${STAGEDIR}${PREFIX}/sbin/argus
.for i in argus-lsof argus-snmp	argus-vmstat argusbug
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${STAGEDIR}${PREFIX}/bin/$i
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/man5/argus.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5/
	${INSTALL_MAN} ${WRKSRC}/man/man8/argus.8 ${STAGEDIR}${PREFIX}/share/man/man8/
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
