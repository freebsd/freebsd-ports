# Ports collection makefile for:	gpt
# Date created:				January 16, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gpt
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	misc archivers devel parallel
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/aces/gpt/releases/gpt-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Grid Packaging Tools (used to install Globus)

RUN_DEPENDS+=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${SITE_PERL}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib \
		${SITE_PERL}/Pod/Parser.pm:${PORTSDIR}/textproc/p5-PodParser \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${LOCALBASE}/bin/gmake:${PORTSDIR}/devel/gmake \
		${LOCALBASE}/bin/makepatch:${PORTSDIR}/textproc/makepatch

USE_PERL=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes

PLIST_SUB+=	PERL=${PERL}

MAN1=		gpt-build.1 gpt-bundle.1 gpt-config.1 gpt-deps.1 \
		gpt-flavor-configuration.1 gpt-install.1 \
		gpt-pkg.1 gpt-postinstall.1 gpt-query.1 gpt-setup.1 \
		gpt-undefines.1 gpt-uninstall.1 gpt-verify.1 \
		gpt-virtual-pkg.1 gpt_build_config.1 \
		gpt_extract_data.1 gpt_generate_bin_pkg_data.1 \
		gpt_save_flavor.1

FIX_VAR_FILES=	${WRKSRC}/packaging_tools/perl/GPT/Localize.pm \
		${WRKSRC}/packaging_tools/perl/GPT/PkgMngmt.pm \
		${WRKSRC}/packaging_tools/perl/GPT/PkgMngmt/Archive.pm \
		${WRKSRC}/packaging_tools/perl/GPT/PkgMngmt/BuildMacros.pm \
		${WRKSRC}/packaging_tools/perl/GPT/PkgMngmt/ExpandSource.pm \
		${WRKSRC}/packaging_tools/perl/scripts/gpt-bundle \
		${WRKSRC}/packaging_tools/perl/scripts/gpt-config \
		${WRKSRC}/tools/testArchiveTar

post-patch:
	@${REINPLACE_CMD} -e "s|@@PERL@@|${PERL}|g" ${WRKSRC}/build_gpt
	@${REINPLACE_CMD} -e 's|$$gpath/var/lib/perl|/var/db/gpt|g' ${FIX_VAR_FILES}
	@${MKDIR} ${WRKSRC}/packaging_tools/etc/gpt

do-install:
	@cd ${WRKSRC}; \
	GPT_LOCATION=${PREFIX} ./build_gpt --with-perl=${PERL}

.include <bsd.port.mk>
