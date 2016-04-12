# Created by: Ryan Steinmetz <rpsfa@rit.edu>
# $FreeBSD$

PORTNAME=		vmware-vsphere-cli
PORTVERSION=		5.5.0
PORTREVISION=		3
CATEGORIES=		net perl5
MASTER_SITES=		#http://communities.vmware.com/community/vmtn/developer/downloads
DISTNAME=		VMware-vSphere-Perl-SDK-${PORTVERSION}-${DISTREL}.i386

MAINTAINER=		zi@FreeBSD.org
COMMENT=		VMware vSphere SDK for Perl with CLI tools

BUILD_DEPENDS=		p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker \
			p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
			p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
			p5-UUID>=0:devel/p5-UUID \
			p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
			p5-SOAP-Lite>=0:net/p5-SOAP-Lite
RUN_DEPENDS=		p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker \
			p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
			p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
			p5-UUID>=0:devel/p5-UUID \
			p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
			p5-SOAP-Lite>=0:net/p5-SOAP-Lite

USES=			perl5 shebangfix
USE_PERL5=		configure
RESTRICTED=		May not be redistributed.  Must accept license to download.
NO_CDROM=		May not be redistributed.  Must accept license to download.
NO_PACKAGE=		May not be redistributed.  Must accept license to download.
SHEBANG_FILES=		bin/* apps/host/* apps/general/* apps/vm/*

DISTREL=		1384587

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
	@${REINPLACE_CMD} -e 's|%%EXAMPLESDIR%%|${STAGEDIR}${EXAMPLESDIR}|g' ${WRKSRC}/Makefile.PL
	@${FIND} ${WRKSRC} -name \*.orig -delete

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vicfg-* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/svmotion ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vmware-cmd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vmkfstools ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vifs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vihostupdate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vihostupdate35 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/viperl-support ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/apps/host/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/apps/general/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/apps/vm/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
