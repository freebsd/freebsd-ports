# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	argus
PORTVERSION=	3.0.6.1
CATEGORIES=	net-mgmt security
MASTER_SITES=	http://qosient.com/argus/src/ \
		ftp://qosient.com/pub/argus/src/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Generic IP network transaction auditing tool

LICENSE=	GPLv3

CONFLICTS=	argus-2* argus-sasl-2* argus-clients-2*

OPTIONS_DEFINE=	SASL MANPAGES
OPTIONS_DEFAULT=SASL MANPAGES

USE_RC_SUBR=	argus

.include <bsd.port.options.mk>

USE_BISON=	build
GNU_CONFIGURE=	true
USE_PERL5=	yes

.if ${PORT_OPTIONS:MSASL}
PKGNAMESUFFIX+=	-sasl
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

MAN5=		argus.conf.5
MAN8=		argus.8

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/lib/sasl2#${LOCALBASE}/lib/sasl2#' ${WRKSRC}/argus/ArgusOutput.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/argus ${PREFIX}/sbin/argus
.for i in argus-lsof argus-snmp	argus-vmstat argusbug
	${INSTALL_SCRIPT} ${WRKSRC}/bin/$i ${PREFIX}/bin/$i
.endfor
	${MKDIR} ${EXAMPLESDIR}/Archive ${EXAMPLESDIR}/Config \
		 ${EXAMPLESDIR}/Deployment ${EXAMPLESDIR}/Startup \
		 ${EXAMPLESDIR}/System
.for i in README \
	Archive/argusarchive \
	Config/argus.conf \
	Deployment/sample \
	Startup/argus Startup/README \
	System/crontab System/magic
	${INSTALL_DATA} ${WRKSRC}/support/$i ${EXAMPLESDIR}/$i
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
.for i in README
	${INSTALL_DATA} ${WRKSRC}/doc/$i ${DOCSDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MMANPAGES}
.for i in ${MAN5}
	${INSTALL_DATA} ${WRKSRC}/man/man5/$i ${MANPREFIX}/man/man5
.endfor
.for i in ${MAN8}
	${INSTALL_DATA} ${WRKSRC}/man/man8/$i ${MANPREFIX}/man/man8
.endfor
.endif

.include <bsd.port.mk>
