# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	nfsen
PORTVERSION=	1.3.6p1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION} \
		http://nfsen.sourceforge.net/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Web based frontend to nfdump netflow collector

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/BSD-license.txt

RUN_DEPENDS=	rrdtool>=0:${PORTSDIR}/databases/rrdtool \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6 \
		nfdump>=0:${PORTSDIR}/net-mgmt/nfdump

USES=	iconv shebangfix perl5
USE_PHP=	session pcre sockets
NO_BUILD=	yes
PLIST_SUB+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-install
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

NO_STAGE=	yes
post-patch:
.for nfsenfile in ${REINPLACE_LIST}
	@${REINPLACE_CMD} ${_SUB_LIST_TEMP} ${WRKSRC}/${nfsenfile}
.endfor
.for perlfile in ${SHEBANG_FILES}
	@${REINPLACE_CMD} "s|perl -w$$|perl|" ${WRKSRC}/${perlfile}
.endfor

do-install:
	${INSTALL} -d ${PREFIX}/var/${PORTNAME}/profiles-data/live
	${INSTALL} -d ${PREFIX}/var/${PORTNAME}/profiles-stat/live
	${INSTALL} -d ${PREFIX}/var/${PORTNAME}/profiles/live
	${INSTALL} -d ${PREFIX}/var/${PORTNAME}/filters
	${INSTALL} -d ${PREFIX}/var/${PORTNAME}/run
	${INSTALL} -d ${PREFIX}/libexec/${PORTNAME}/plugins
	${INSTALL} -d ${WWWDIR}/plugins
	(cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${PREFIX}/bin/)
	${INSTALL_DATA} ${WRKSRC}/etc/nfsen-dist.conf ${PREFIX}/etc/
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${WWWDIR}/)
	(cd ${WRKSRC}/plugins/frontend/ && ${COPYTREE_SHARE} . ${WWWDIR}/plugins/)
	(cd ${WRKSRC}/libexec && ${INSTALL_SCRIPT} * ${PREFIX}/libexec/${PORTNAME}/)
	(cd ${WRKSRC}/plugins/backend && ${COPYTREE_SHARE} . ${PREFIX}/libexec/${PORTNAME}/plugins/)
	${INSTALL_DATA} ${WRKSRC}/installer-items/CopyRecursive.pm ${PREFIX}/libexec/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/installer-items/RRDconvertv1.pm ${PREFIX}/libexec/${PORTNAME}/
	@${ECHO_MSG} "Configure your ${LOCALBASE}/etc/nfsen.conf to have necessary sources ";
	@${ECHO_MSG} "Then run 'nfsen reconfig' to correctly setup source, RRD, and profile files";

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
