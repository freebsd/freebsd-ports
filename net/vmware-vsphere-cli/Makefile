# New ports collection makefile for:	vmware-vsphere-cli
# Date created:				2011-07-07
# Whom:					rpsfa@rit.edu
#
# $FreeBSD$
#

PORTNAME=		vmware-vsphere-cli
PORTVERSION=		4.1.0
CATEGORIES=		net perl5
MASTER_SITES=		#http://communities.vmware.com/community/vmtn/developer/downloads
DISTNAME=		VMware-vSphere-Perl-SDK-${PORTVERSION}-${DISTREL}.i386

MAINTAINER=		rpsfa@rit.edu
COMMENT=		VMware vSphere SDK for Perl with CLI tools

BUILD_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
			${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
			${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
			${SITE_PERL}/${PERL_ARCH}/UUID.pm:${PORTSDIR}/devel/p5-UUID \
			${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
			${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
			${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
			${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
			${SITE_PERL}/${PERL_ARCH}/UUID.pm:${PORTSDIR}/devel/p5-UUID \
			${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
			${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite

PERL_CONFIGURE=		yes
RESTRICTED=		Downloading requires acceptance of license agreement
NO_CDROM=		Distribution requires acceptance of license agreement
NO_PACKAGE=		Distribution requires acceptance of license agreement

MAN3=			VMware::VIM25Runtime.3 VMware::VIM2Stub.3 VMware::VIM2Runtime.3 \
			VMware::VICommon.3 VMware::VILib.3 VMware::VIM25Stub.3

DISTREL=		254719

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

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
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

.include <bsd.port.post.mk>
