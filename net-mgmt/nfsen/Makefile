# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	nfsen
PORTVERSION=	1.3.7
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION} \
		http://nfsen.sourceforge.net/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Web based frontend to nfdump netflow collector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

RUN_DEPENDS=	rrdtool>=0:databases/rrdtool \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-Socket6>=0:net/p5-Socket6 \
		nfdump>=0:net-mgmt/nfdump

USES=		cpe iconv shebangfix perl5
CPE_VENDOR=	nfsen
CPE_PRODUCT=	nfsen
USE_PHP=	session pcre sockets
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME}
USE_RC_SUBR=	nfsen
perl_OLD_CMD=	%%PERL%%
SHEBANG_FILES=	bin/testPlugin bin/RebuildHierarchy.pl bin/nfsen bin/nfsend libexec/NfSenRRD.pm \
		libexec/NfAlert.pm libexec/NfProfile.pm libexec/Notification.pm libexec/NfSen.pm \
		libexec/NfConf.pm libexec/Lookup.pm libexec/AbuseWhois.pm libexec/NfSenRC.pm \
		libexec/Nfsources.pm
REINPLACE_ARGS=	-i ''
REINPLACE_LIST=	bin/testPlugin bin/RebuildHierarchy.pl bin/nfsen bin/nfsend etc/nfsen-dist.conf libexec/NfConf.pm
SUB_LIST+=	"CONFDIR=${PREFIX}/etc"
SUB_LIST+=	"LIBEXECDIR=${PREFIX}/libexec/${PORTNAME}"
SUB_LIST+=	"PORTVERSION=${PORTVERSION}"
SUB_LIST+=	"PREFIX=${PREFIX}"
SUB_LIST+=	"WWWDIR=${WWWDIR}"
SUB_LIST+=	"PORTNAME=${PORTNAME}"

post-patch:
.for nfsenfile in ${REINPLACE_LIST}
	@${REINPLACE_CMD} ${_SUB_LIST_TEMP} ${WRKSRC}/${nfsenfile}
.endfor
.for perlfile in ${SHEBANG_FILES}
	@${REINPLACE_CMD} "s|perl -w$$|perl|" ${WRKSRC}/${perlfile}
.endfor
	${CP} ${FILESDIR}/conf.php ${WRKSRC}
	@${REINPLACE_CMD} ${_SUB_LIST_TEMP} ${WRKSRC}/conf.php
	@${REINPLACE_CMD} "s|/usr/bin/perl|${perl_CMD}|" ${WRKSRC}/libexec/Nfcomm.pm

do-install:
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/var/${PORTNAME}/profiles-data/live
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/var/${PORTNAME}/profiles-stat/live
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/var/${PORTNAME}/profiles/live
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/var/${PORTNAME}/filters
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/var/${PORTNAME}/run
	${INSTALL} -d ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/plugins
	${INSTALL} -d ${STAGEDIR}/${WWWDIR}/plugins
	(cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${STAGEDIR}/${PREFIX}/bin/)
	${INSTALL_DATA} ${WRKSRC}/etc/nfsen-dist.conf ${STAGEDIR}/${PREFIX}/etc/
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/)
	(cd ${WRKSRC}/plugins/frontend/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/plugins/)
	(cd ${WRKSRC}/libexec && ${INSTALL_SCRIPT} * ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/)
	(cd ${WRKSRC}/plugins/backend && ${COPYTREE_SHARE} . ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/plugins/)
	${INSTALL_DATA} ${WRKSRC}/installer-items/CopyRecursive.pm ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/installer-items/RRDconvertv1.pm ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/conf.php ${STAGEDIR}/${WWWDIR}
	@${ECHO_MSG} "Configure your ${LOCALBASE}/etc/nfsen.conf to have necessary sources ";
	@${ECHO_MSG} "Then run 'nfsen reconfig' to correctly setup source, RRD, and profile files";

.include <bsd.port.mk>
