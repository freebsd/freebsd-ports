# Ports collection makefile for:	gpt
# Date created:				January 16, 2004
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gpt
PORTVERSION=	3.1
PORTREVISION=	5
CATEGORIES=	misc archivers devel parallel
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/aces/gpt/releases/gpt-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Grid Packaging Tools (used to install Globus)

CONFLICTS=	gpt-*
NO_LATEST_LINK=	YES

RUN_DEPENDS+=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/IO/Zlib.pm:${PORTSDIR}/archivers/p5-IO-Zlib \
		${LOCALBASE}/bin/gmake:${PORTSDIR}/devel/gmake \
		${LOCALBASE}/bin/makepatch:${PORTSDIR}/textproc/makepatch

BROKEN=		pkg_add broken in 9.0 amd64, make broken in 7.4 i386
DEPRECATED=	was a dependency for net/globus4, which was removed 2008-12-07, unmaintained upstream since 2004
EXPIRATION_DATE=2012-08-10

USE_PERL5=	yes
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
