# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=		vmware-vsphere-cli
PORTVERSION=		5.1.0
CATEGORIES=		net perl5
MASTER_SITES=		#http://communities.vmware.com/community/vmtn/developer/downloads
DISTNAME=		VMware-vSphere-Perl-SDK-${PORTVERSION}-${DISTREL}.i386

MAINTAINER=		zi@FreeBSD.org
COMMENT=		VMware vSphere SDK for Perl with CLI tools

BUILD_DEPENDS=		p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker \
			p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
			p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
			p5-UUID>=0:${PORTSDIR}/devel/p5-UUID \
			p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
			p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=		p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker \
			p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
			p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
			p5-UUID>=0:${PORTSDIR}/devel/p5-UUID \
			p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
			p5-SOAP-Lite>=0:${PORTSDIR}/net/p5-SOAP-Lite

USES=			perl5
USE_PERL5=		configure
RESTRICTED=		Downloading requires acceptance of license agreement
NO_CDROM=		Distribution requires acceptance of license agreement
NO_PACKAGE=		Distribution requires acceptance of license agreement

MAN3=			VMware::VIM25Runtime.3 VMware::VIM2Stub.3 VMware::VIM2Runtime.3 \
			VMware::VICommon.3 VMware::VILib.3 VMware::VIM25Stub.3

DISTREL=		780721

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
DISTFILE_INSTRUCTIONS=\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n\
Please visit http://communities.vmware.com/community/vmtn/developer/forums/vsphere_sdk_perl\n\
and choose Download.  Then, login using a VMware account and accept the license agreement.\n\
Choose the download for vSphere SDK for Perl - 32-bit Linux Installer (even if you are not on i386)\n\n\
After the download has completed, please place ${DISTNAME}${EXTRACT_SUFX} in\n\
${DISTDIR}, then restart the build.\n\n
.endif

.if defined(DISTFILE_INSTRUCTIONS)
.if defined(PACKAGE_BUILDING)
IGNORE=		requires manual fetch
.else
pre-fetch:
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-distrib ${WRKSRC}
	@${RM} ${WRKSRC}/vmware-install.pl

post-patch:
	@${REINPLACE_CMD} -e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|g' ${WRKSRC}/Makefile.PL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vicfg-* ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/svmotion ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vmware-cmd ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vmkfstools ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vifs ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vihostupdate ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vihostupdate35 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/viperl-support ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
